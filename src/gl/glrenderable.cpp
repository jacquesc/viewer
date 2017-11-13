#include <iostream>
#include <functional>

#include <gl/glhandle.h>
#include <gl/shaderfactory.h>
#include <glsl/shaderprogram/simplecolor.h>
#include <glsl/shaderprogram/simplelight.h>

#include <gl/glrenderable.h>

GLRenderable::GLRenderable(Presets::Shaders preset) 
	: Renderable(), mInit(false), mShaderType(preset) {
}

GLRenderable::~GLRenderable() {

}

void GLRenderable::draw(Camera *camera) {
	if (!mInit) {
		setupRenderPrimitives();
		mInit = true;
	}

	ShaderProgram *shaderProgram = ShaderFactory::getInstance()->getPresetShader(mShaderType);
	glUseProgram(shaderProgram->getHandle());
	glBindVertexArray(mVao);	
	// FIXME: polymorphism
	((SimpleLightProgram *)shaderProgram)->updateUniform(camera, this);
	glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void GLRenderable::setupVertexAttributes(GLuint shaderProgram, std::vector<Attribute>& attributes) {
	GLuint vbo[1]; 
	glGenVertexArrays(1, &mVao);
	glBindVertexArray(mVao);
	glGenBuffers(1, vbo);

	std::cout << "Setup vertex attributes " << mVao << std::endl;
 
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * mVertices.size(), &mVertices[0], GL_STATIC_DRAW);

	Attribute vertex(shaderProgram, "aVertex");
	vertex.setupAttributePointer(3);
	attributes.push_back(vertex);

	if (mShaderType == Presets::Shaders::SIMPLE_LIGHT) {
		std::cout << "Setup normal attributes " << mVao << std::endl;
		GLuint normalBuffer[1];
		glGenBuffers(1, normalBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * mNormals.size(), &mNormals[0], GL_STATIC_DRAW);

		Attribute normal(shaderProgram, "aNormal");
		normal.setupAttributePointer(3);
		attributes.push_back(normal);
	}

	GLuint location = 0;
	for (auto a : attributes) {
		glBindAttribLocation(shaderProgram, location++, a.name.c_str());
		std::cout << a.name << " " << a.handle << std::endl;
	}
}

void GLRenderable::setupRenderPrimitives() {
	ShaderFactory *shaderFactory = ShaderFactory::getInstance();
	// std::function<void()> attribCallback = std::bind(&GLRenderable::setupVertexAttributes, this);
	// Creation
	ShaderProgram *shaderProgram = shaderFactory->getPresetShader(mShaderType);
	setupVertexAttributes(shaderProgram->getHandle(), shaderProgram->getAttributes());
}

void GLRenderable::setupRenderPrimitives(const std::string& vertexShader, const std::string& fragmentShader) {
}