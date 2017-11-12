#include <gl/glrenderable.h>

GLRenderable::GLRenderable() : Renderable() {

}

GLRenderable::~GLRenderable() {

}

void GLRenderable::draw(Camera *camera) {
	glUseProgram(mShaderProgram);
	glBindVertexArray(mVao);

	// Update camera matrix

	glDrawArrays(GL_TRIANGLES, 0, 10); // FIXME
}

void GLRenderable::setupVertexAttributes() {
	GLuint vbo[1]; 
	glGenVertexArrays(1, &mVao);
	glBindVertexArray(mVao);
	glGenBuffers(1, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	// FIXME:
	glBufferData(GL_ARRAY_BUFFER, 0, 0, GL_STATIC_DRAW);
	// FIXME:
	glVertexAttribPointer(0, 0, GL_FLOAT, GL_FALSE, 0, 0);
	
	glEnableVertexAttribArray(0);
	glDisableVertexAttribArray(0);
}

void GLRenderable::setupRenderPrimitives(const std::string& vertexShader, const std::string& fragmentShader) {

}