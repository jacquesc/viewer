#version 330

uniform mat4 uModel;
uniform vec3 uLightPos;

in vec3 modelNormal;
in vec3 modelVert;

out vec4 fragColor;

void main() {
	mat3 normalMatrix = transpose(inverse(mat3(uModel)));
	vec3 normal = normalize(normalMatrix * modelNormal);
	
	vec3 p = vec3(uModel * vec4(modelVert, 1.0));
	vec3 L = normalize(modelVert - uLightPos);

	float diffuse = max(0.0, dot(normal, L));
	fragColor = vec4(diffuse * vec3(1.0), 1.0);
}