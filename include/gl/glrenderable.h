#pragma once

#include <string>

#include <nanogui/opengl.h>

#include <gl/shaderprogram.h>
#include <glsl/presets.h>
#include <renderable/renderable.h>

class GLRenderable : public Renderable {
public:
	GLRenderable(Presets::Shaders preset = Presets::Shaders::SIMPLE_LIGHT);
	virtual ~GLRenderable();

	void draw(Camera *camera);
private:
	void setupVertexAttributes(GLuint shaderProgram, std::vector<Attribute>& attributes);
	void setupRenderPrimitives();
	void setupRenderPrimitives(const std::string& vertexShader, const std::string& fragmentShader);

	// VAO
	GLuint mVao;
	bool mInit;
	Presets::Shaders mShaderType;
};