#include <iostream>

#include <camera.h>
#include <gl/glrenderable.h>

#include <gl/shaderprogram.h>

namespace {
	static const size_t UMVP_INDEX = 0;
}

ShaderProgram::ShaderProgram() {

}

ShaderProgram::ShaderProgram(GLuint shaderProgram) : mShaderProgram(shaderProgram) {

}

void ShaderProgram::updateUniform(const Camera * camera, GLRenderable *renderable) {
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