#include <renderable/renderable.h>

Renderable::Renderable() {
}

Renderable::~Renderable() {
}

void Renderable::draw() {
}

void Renderable::setModelData(const tinyobj::attrib_t attributes,
	const std::vector<tinyobj::shape_t>& shapes) {
	mAttributes = attributes;
	mShapes = shapes;
}
