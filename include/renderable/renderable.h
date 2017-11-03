#pragma once

#include <vector>

#include <tiny_obj_loader.h>

class Renderable {
public:
	Renderable();
	virtual ~Renderable();

	void draw();

	void setModelData(const tinyobj::attrib_t attributes, 
		const std::vector<tinyobj::shape_t>& shapes);

private:
	std::vector<tinyobj::shape_t> mShapes;
	tinyobj::attrib_t mAttributes;
	// TODO: Transform

	// VAO
};