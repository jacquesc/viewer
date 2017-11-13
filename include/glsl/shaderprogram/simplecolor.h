#pragma once

#include <nanogui/opengl.h>

#include <gl/shaderprogram.h>

class Camera;

class SimpleColorProgram : public ShaderProgram {
public:
	SimpleColorProgram();
	SimpleColorProgram(GLuint shaderProgram);
	void updateUniform(Camera *camera, GLRenderable *renderable);
};