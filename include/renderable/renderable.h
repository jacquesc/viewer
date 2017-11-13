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

	void getTransform(glm::mat4& transform);

	virtual void draw(Camera *camera) = 0;

protected:
	std::vector<glm::vec3> mVertices;
	std::vector<glm::vec3> mNormals;
	glm::mat4 mModelMatrix;

private:
	void calculateNormals();
};