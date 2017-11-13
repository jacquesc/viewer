#include <iostream>

#include <gl/shaderprogram.h>

ShaderProgram::ShaderProgram() {

}

ShaderProgram::ShaderProgram(GLuint shaderProgram) : mShaderProgram(shaderProgram) {

}

void ShaderProgram::updateUniform(Camera * camera, GLRenderable *renderable) {
}