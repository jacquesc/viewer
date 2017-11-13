#pragma once

#include <string>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <nanogui/opengl.h>

struct GLHandle {
	GLint handle;
	GLuint shader;
	std::string name;
	GLHandle(GLuint shader, const std::string& name, GLuint handle = -1) {
		this->handle = handle;
		this->shader = shader;
		this->name = name;
	}
};

struct Attribute : public GLHandle {
	Attribute(GLuint shader, const std::string& name) 
		: GLHandle(shader, name) {
		handle = glGetAttribLocation(shader, name.c_str());
	}

	void setupAttributePointer(size_t size) {
		glEnableVertexAttribArray(handle);
		glVertexAttribPointer(handle, size, GL_FLOAT, GL_FALSE, 0, 0);
	}
};


enum UniformType {
	MATRIX_4
};

struct Uniform : public GLHandle {
	Uniform(GLuint shader, const std::string& name) 
		: GLHandle(shader, name) {
		handle = glGetUniformLocation(shader, name.c_str());
	}
	// matrix4
	void setUniformData(const glm::mat4& matrix) {
		glUniformMatrix4fv(handle, 1, GL_FALSE, &matrix[0][0]);
	}
};