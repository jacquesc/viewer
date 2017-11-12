#pragma once

#include <vector>

#include <glm/mat4x4.hpp>
#include <tiny_obj_loader.h>

class Camera;

class Renderable {
public:
	Renderable();
	virtual ~Renderable();

	void setModelData(const tinyobj::attrib_t attributes, 
		const std::vector<tinyobj::shape_t>& shapes);

	void getTransform(glm::mediump_mat4& transform) const;

	virtual void draw(Camera *camera) = 0;

private:
	std::vector<tinyobj::shape_t> mShapes;
	tinyobj::attrib_t mAttributes;
	// TODO: Transform
};