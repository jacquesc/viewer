#include <renderable/renderable.h>

Renderable::Renderable() {
}

Renderable::~Renderable() {
}

void Renderable::setModelData(const tinyobj::attrib_t attributes,
	const std::vector<tinyobj::shape_t>& shapes) {
	mAttributes = attributes;
	mShapes = shapes;
}

void Renderable::getTransform(glm::mediump_mat4& transform) const {
	// TEMP: identity matrix
	transform = glm::mat4(1.0f);
}
