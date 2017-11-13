#version 330

in vec3 aVertex;
uniform mat4 uMVP;

void main() {
	gl_Position = uMVP * vec4(aVertex, 1.0);
}