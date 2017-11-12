#pragma once

#include <nanogui/opengl.h>
#include <gl/glhandle.h>

class ShaderProgram {
public:
	ShaderProgram();
	virtual void setupUniform();
	virtual void setupAttribute();


private:
	GLuint mShaderProgram;
	Attribute *mAttributeLocation;
	Uniform *mUniforms;
};