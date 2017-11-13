#version 330

in vec3 aVertex;
in vec3 aNormal;

uniform mat4 uMVP;

out vec3 modelNormal;
out vec3 modelVert;

void main() {
	modelNormal = aNormal;
	modelVert = aVertex;
	gl_Position = uMVP * vec4(aVertex, 1.0);
}