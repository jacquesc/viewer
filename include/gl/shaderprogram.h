#pragma once

#include <vector>

#include <nanogui/opengl.h>
#include <gl/glhandle.h>

class Camera;
class GLRenderable;

class ShaderProgram {
public:
	ShaderProgram();
	ShaderProgram(GLuint shaderProgram);
	virtual void updateUniform(const Camera * camera, GLRenderable *renderable);
	GLuint getHandle() const { return mShaderProgram; }

	std::vector<Attribute>& getAttributes() { return mAttributes; }
	std::vector<Uniform>& getUniforms() { return mUniforms; }

protected:
	GLuint mShaderProgram;
	std::vector<Attribute> mAttributes;
	std::vector<Uniform> mUniforms;

};