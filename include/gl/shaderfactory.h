#pragma once
#include <nanogui/opengl.h>

class ShaderFactory {

enum ShaderType {
	COLOR,
	SIMPLE,
	LIGHTING
};

public:
	static ShaderFactory *getInstance();
	GLuint createVertexShader(const char *shaderFile);
	GLuint createFragmentShader(const char *shaderFile);
	GLuint createShaderProgram(GLuint vertex, GLuint fragment);
private:
	ShaderFactory();
};