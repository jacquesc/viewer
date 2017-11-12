#include <gl/shaderfactory.h>

namespace {
	static ShaderFactory *sInstance = NULL;
}

ShaderFactory *ShaderFactory::getInstance() {
	if (!sInstance) {
		sInstance = new ShaderFactory();
	}
	return sInstance;
}

GLuint ShaderFactory::createVertexShader(const char *shaderFile) {
	return 0;
}

GLuint ShaderFactory::createFragmentShader(const char *shaderFile) {
	return 0;
}

GLuint ShaderFactory::createShaderProgram(GLuint vertex, GLuint fragment) {
	return 0;
}

ShaderFactory::ShaderFactory() {

}