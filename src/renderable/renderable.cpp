#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include <renderable/renderable.h>

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

			mNormals.push_back(glm::vec3(attributes.normals[3 * index.normal_index + 0],
				attributes.normals[3 * index.normal_index + 1],
				attributes.normals[3 * index.normal_index + 2]));
		}
	}

	std::cout << "# Vertices: " << mVertices.size() << std::endl;
	std::cout << "# Normals: " << mNormals.size() << std::endl;
}

void Renderable::getTransform(glm::mat4& transform) {
	// TEMP: identity matrix
	transform = glm::mat4(1.f);
}
