#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <camera.h>

namespace {
	static const glm::vec3 DEFAULT_POSITION = glm::vec3(0, 0, 5);
	static const glm::vec3 DEFAULT_LOOKAT = glm::vec3(0,0,0);
	static const glm::vec3 DEFAULT_UP = glm::vec3(0,1,0);
}

Camera::Camera() : mRotation(1.f), mProjection(1.f) {
}

Camera::~Camera() {
}

void Camera::setCameraSettings(float fovy, float aspect, float near, float far) {
	mProjection = glm::perspective(fovy, aspect, near, far);
}

void Camera::setViewport(int x, int y, int width, int height) {
	mViewportPosition.x = x;
	mViewportPosition.y = y;
	
	mViewportSize.x = width;
	mViewportSize.y = height;
}

void Camera::getViewport(int &x, int &y, int &width, int &height) {
	x = mViewportPosition.x;
	y = mViewportPosition.y;
	width = mViewportSize.x;
	height = mViewportSize.y;
}

void Camera::getProjectionMatrix(glm::mat4& projectionMatrix) const {
	projectionMatrix = mProjection;
}

void Camera::getViewMatrix(glm::mat4& viewMatrix) const {
	viewMatrix = glm::lookAt(DEFAULT_POSITION + mDeltaPosition,
			DEFAULT_LOOKAT + mDeltaPosition, DEFAULT_UP);
	viewMatrix *= mRotation;
}

void Camera::updateTrackball(float rotation[4][4]) {
	float m[16];
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			m[i * 4 + j] = rotation[i][j];
		}
	}
	mRotation = glm::make_mat4(m);
}

void Camera::zoom(float zoom) {
	mDeltaPosition.z += zoom;
}
