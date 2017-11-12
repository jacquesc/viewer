#pragma once

#include <string>

#include <nanogui/opengl.h>

struct GLHandle {
	GLuint handle;
	std::string name;
};

struct Attribute : public GLHandle {

};


enum UniformType {
	MATRIX_4
};

struct Uniform : public GLHandle {
	// matrix4
	void setUniformData(UniformType type, float *data) {
		if (type == MATRIX_4) {
		}
	}
};