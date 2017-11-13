#pragma once

#include <gl/shaderprogram.h>

class SimpleLightProgram : public ShaderProgram {
public:
	SimpleLightProgram();
	SimpleLightProgram(GLuint shaderProgram);
	void updateUniform(Camera *camera, GLRenderable *renderable);
};