#include <iostream>
#include <functional>

#include <gl/shaderfactory.h>
#include <glsl/shaderprogram/simplecolor.h>
#include <gl/glrenderable.h>

GLRenderable::GLRenderable(Presets::Shaders preset) 
	: Renderable(), mInit(false), mShaderType(preset) {
}

GLRenderable::~GLRenderable() {

}

void GLRenderable::draw(Camera *camera) {
	if (!mInit) {
		setupRenderPrimitives();
		mInit = true;
	}

	ShaderProgram *shaderProgram = ShaderFactory::getInstance()->getPresetShader(mShaderType);
	glUseProgram(shaderProgram->getHandle());
	glBindVertexArray(mVao);	
	// FIXME: polymorphism
	((SimpleColorProgram *)shaderProgram)->updateUniform(camera, this);
	glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void GLRenderable::setupVertexAttributes() {
	GLuint vbo[1]; 
	glGenVertexArrays(1, &mVao);
	glBindVertexArray(mVao);
	glGenBuffers(1, vbo);

	std::cout << "Setup vertex attributes " << mVao << std::endl;
 
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * mVertices.size(), &mVertices[0], GL_STATIC_DRAW);
}

void GLRenderable::setupRenderPrimitives() {
	ShaderFactory *shaderFactory = ShaderFactory::getInstance();
	std::function<void()> attribCallback = std::bind(&GLRenderable::setupVertexAttributes, this);
	// Creation
	shaderFactory->getPresetShader(mShaderType, &attribCallback);
}

void GLRenderable::setupRenderPrimitives(const std::string& vertexShader, const std::string& fragmentShader) {
}