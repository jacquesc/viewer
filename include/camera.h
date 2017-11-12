#pragma once

#include <iostream>

#include <glm/mat4x4.hpp>

class Camera {

public:
	Camera();
	virtual ~Camera();

	void setCameraSettings(float fovy, float aspect, float near, float far);
	void setViewport(int x, int y, int width, int height);

	void getProjectionMatrix(glm::mediump_mat4& projectionMatrix);
	void getViewMatrix(glm::mediump_mat4& viewMatrix);

private:
	// TODO: orientation
	glm::vec4 mPosition;
	glm::mediump_mat4 mProjection;
	glm::vec2 mViewportSize;
	glm::vec2 mViewportPosition;
};