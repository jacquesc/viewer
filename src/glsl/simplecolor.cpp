#include <iostream>

#include <glm/mat4x4.hpp>

#include <camera.h>
#include <gl/glrenderable.h>

#include <glsl/shaderprogram/simplecolor.h>

namespace {
	static const size_t UMVP_INDEX = 0;
}

SimpleColorProgram::SimpleColorProgram() {

}

SimpleColorProgram::SimpleColorProgram(GLuint shaderProgram) 
	: ShaderProgram(shaderProgram) {
}

void SimpleColorProgram::updateUniform(Camera * camera, GLRenderable *renderable) {
	if (camera) {
		glm::mat4 viewMatrix(1.f), projectionMatrix(1.f);
		camera->getProjectionMatrix(projectionMatrix);
		camera->getViewMatrix(viewMatrix);
		glm::mat4 model;
		renderable->getTransform(model);
		glm::mat4 mvp = projectionMatrix * viewMatrix * model;
		mUniforms[UMVP_INDEX].setUniformData(mvp);
	}
}