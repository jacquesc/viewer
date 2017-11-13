#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include <renderable/renderable.h>

namespace {
	static float ROTATION_ANGLE = 0.f;
}

Renderable::Renderable() {
}

Renderable::~Renderable() {
}

void Renderable::setModelData(const tinyobj::attrib_t attributes,
	const std::vector<tinyobj::shape_t>& shapes) {
	
	for (const auto& shape : shapes) {
		for (const auto& index : shape.mesh.indices) {
			mVertices.push_back(glm::vec3(attributes.vertices[3 * index.vertex_index + 0],
				attributes.vertices[3 * index.vertex_index + 1],
				attributes.vertices[3 * index.vertex_index + 2]));
		}
	}
	std::cout << "# Vertices: " << mVertices.size() << std::endl;
}

void Renderable::getTransform(glm::mat4& transform) {
	// TEMP: identity matrix
	transform = glm::mat4(1.f);
}
