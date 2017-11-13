#include <iostream>

#include <glm/mat4x4.hpp>

#include <camera.h>
#include <gl/glrenderable.h>

#include <glsl/shaderprogram/simplecolor.h>

SimpleColorProgram::SimpleColorProgram() {

}

SimpleColorProgram::SimpleColorProgram(GLuint shaderProgram) 
	: ShaderProgram(shaderProgram) {
}

void SimpleColorProgram::updateUniform(Camera * camera, GLRenderable *renderable) {
	ShaderProgram::updateUniform(camera, renderable);
}