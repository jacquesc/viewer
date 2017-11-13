#pragma once

#include <unordered_map>

#include <nanogui/opengl.h>

#include <gl/shaderprogram.h>
#include <glsl/presets.h>

class ShaderFactory {

public:
	static ShaderFactory *getInstance();
	ShaderProgram *getPresetShader(Presets::Shaders preset, 
		std::function<void()>* attributesCallback = NULL);

	void createUniform(Presets::Shaders preset, GLuint shaderProgram, std::vector<Uniform>& uniforms);
	void createVertexAttributes(Presets::Shaders preset, GLuint shaderProgram, std::vector<Attribute>& attributes);

private:
	GLuint createVertexShader(const std::string& shaderFile);
	GLuint createFragmentShader(const std::string& shaderFile);
	GLuint createShaderProgram(GLuint vertex, GLuint fragment);
	ShaderFactory();

	std::unordered_map<Presets::Shaders, ShaderProgram *> mPresetShaders;
};