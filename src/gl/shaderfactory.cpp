#include <fstream>
#include <iostream>

#include <gl/shaderfactory.h>
#include <glsl/shaderprogram/simplecolor.h>

namespace {
	static ShaderFactory *sInstance = NULL;

	// Boilerplate: https://www.khronos.org/opengl/wiki/Shader_Compilation
	void handleShaderError(GLuint shader, const std::string& shadertype) {
		GLint isCompiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if(isCompiled == GL_FALSE) {
			GLint maxLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
			
			std::cout << "[ERROR]: " << shadertype << std::endl;
			for (size_t i = 0; i < infoLog.size(); i++) {
				std::cout << infoLog[i];
			}
			glDeleteShader(shader);
		} else {
			std::cout << "Shader " << shadertype << " successful!" << std::endl;
		}
	}

	void handleLinkProgramError(GLuint program, GLuint vertex, GLuint fragment) {
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
		if(isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
			
			glDeleteProgram(program);
			glDeleteShader(vertex);
			glDeleteShader(fragment);

			for (size_t i = 0; i < infoLog.size(); i++) {
				std::cout << infoLog[i];
			}
		} else {
			std::cout << "Program successful!" << std::endl;
		}
	}

	GLuint createShader(const std::string& shaderFile, GLuint shaderType) {
		GLuint shader = 0;
		std::ifstream ifs;
		ifs.open(shaderFile);
		if (ifs.is_open()) {
			shader = glCreateShader(shaderType);
			// https://stackoverflow.com/a/2912614
			std::string source((std::istreambuf_iterator<char>(ifs)),
                       (std::istreambuf_iterator<char>()));
			GLint length = source.size();
			const char *source_c = source.c_str();
			glShaderSource(shader, 1, &source_c, &length);
			glCompileShader(shader);
			handleShaderError(shader, shaderFile);
		} else {
			std::cerr << "Shader file '" << shaderFile << "' did not load" << std::endl;
		}
		ifs.close();
		return shader;
	}
}

ShaderFactory *ShaderFactory::getInstance() {
	if (!sInstance) {
		sInstance = new ShaderFactory();
	}
	return sInstance;
}

ShaderProgram *ShaderFactory::getPresetShader(Presets::Shaders preset, 
	std::function<void()>* attributesCallback) {
	GLuint vertex = 0, fragment = 0;
	if (mPresetShaders.find(preset) == mPresetShaders.end()) {
		vertex = createVertexShader(Presets::simpleVert());
		fragment = createFragmentShader(Presets::colorFrag());
		if (preset == Presets::SIMPLE_COLOR) {
			std::cout << "Creating preset shader SIMPLE_COLOR" << std::endl;
			mPresetShaders[preset] = new SimpleColorProgram(createShaderProgram(vertex, fragment));
		}
		// Set up shader specific things
		if (attributesCallback) {
			std::function<void()> cb = *attributesCallback;
			cb();
		}

		ShaderProgram *shaderProgram = mPresetShaders[preset];
		int p = shaderProgram->getHandle();
		std::cout << p << std::endl;
		glAttachShader(p, vertex);
		glAttachShader(p, fragment);

		glLinkProgram(p);
		handleLinkProgramError(p, vertex, fragment);

		createUniform(preset, p, shaderProgram->getUniforms());
		createVertexAttributes(preset, p, shaderProgram->getAttributes());

		glDetachShader(p, vertex);
		glDetachShader(p, fragment);
	}

	return mPresetShaders[preset];
}

void ShaderFactory::createVertexAttributes(Presets::Shaders preset, GLuint shaderProgram, std::vector<Attribute>& attributes) {
	if (preset == Presets::SIMPLE_COLOR) {
		Attribute vertex(shaderProgram, "aVertex");
		vertex.setupAttributePointer(3);
		attributes.push_back(vertex);

		GLuint location = 0;
		for (auto a : attributes) {
			glBindAttribLocation(shaderProgram, location++, a.name.c_str());
			std::cout << a.name << " " << a.handle << std::endl;
		}
	}
}

void ShaderFactory::createUniform(Presets::Shaders preset, GLuint shaderProgram, std::vector<Uniform>& uniforms) {
	if (preset == Presets::SIMPLE_COLOR) {
		// Uniform color(shaderProgram, "uColor");
		// uniforms.push_back(color);

		Uniform mvp(shaderProgram, "uMVP");
		uniforms.push_back(mvp);
		
		for (auto u : uniforms) {
			std::cout << u.name << " " << u.handle << std::endl;
		}
	}
}

GLuint ShaderFactory::createVertexShader(const std::string& shaderFile) {
	return createShader(shaderFile, GL_VERTEX_SHADER);
}

GLuint ShaderFactory::createFragmentShader(const std::string& shaderFile) {
	return createShader(shaderFile, GL_FRAGMENT_SHADER);
}

GLuint ShaderFactory::createShaderProgram(GLuint vertex, GLuint fragment) {
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(vertex, GL_VERTEX_SHADER);
	glAttachShader(fragment, GL_FRAGMENT_SHADER);
	return shaderProgram;
}

ShaderFactory::ShaderFactory() {

}