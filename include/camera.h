#pragma once

#include <iostream>

#include <glm/mat4x4.hpp>

class Camera {

public:
	Camera();
	virtual ~Camera();

	void setCameraSettings(float fovy, float aspect, float near, float far);
	void setViewport(int x, int y, int width, int height);
	void getViewport(int& x, int& y, int& width, int& height);

	void getProjectionMatrix(glm::mat4& projectionMatrix) const;
	void getViewMatrix(glm::mat4& viewMatrix) const;

	void updateTrackball(float rotation[4][4]);

	void zoom(float zoom);

private:
	glm::mat4 mRotation;

	glm::mat4 mProjection;
	glm::vec2 mViewportSize;
	glm::vec2 mViewportPosition;

	glm::vec3 mDeltaPosition;
};
