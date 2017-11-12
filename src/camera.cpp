#include <glm/gtc/matrix_transform.hpp>

#include <camera.h>

Camera::Camera() : mPosition(0.f), mProjection(1.f) {

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

void Camera::getProjectionMatrix(glm::mediump_mat4& projectionMatrix) {
	projectionMatrix = mProjection;
}

void Camera::getViewMatrix(glm::mediump_mat4& viewMatrix) {
	// TEMP:
	viewMatrix = glm::lookAt(glm::vec3(mPosition), glm::vec3(0.f, 0.f, 3.f), glm::vec3(0.f, 0.f, 1.f));
}