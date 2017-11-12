#pragma once

#include <nanogui/opengl.h>

#include <string>
#include <renderable/renderable.h>

class GLRenderable : public Renderable {
public:
	GLRenderable();
	virtual ~GLRenderable();

	void draw(Camera *camera);

	void setupVertexAttributes();
	void setupRenderPrimitives(const std::string& vertexShader, const std::string& fragmentShader);

private:
	// VAO
	GLuint mVao;
	GLuint mShaderProgram;
	
};