#include <camera.h>

#include <gl/glrenderable.h>

#include <glsl/shaderprogram/simplelight.h>

namespace {
	static const size_t UMODEL_INDEX = 1;
	static const size_t ULIGHT_INDEX = 2;
}

SimpleLightProgram::SimpleLightProgram() {

}

SimpleLightProgram::SimpleLightProgram(GLuint shaderProgram) 
	: ShaderProgram(shaderProgram) {
}

void SimpleLightProgram::updateUniform(const Camera * camera, GLRenderable *renderable) {
	ShaderProgram::updateUniform(camera, renderable);

	glm::mat4 modelMatrix;
	renderable->getTransform(modelMatrix);
	mUniforms[UMODEL_INDEX].setUniformData(modelMatrix);

	// straight above
	glm::vec3 lightPos(5.f, -2.f, 2.f);
	mUniforms[ULIGHT_INDEX].setUniformData(lightPos);

}