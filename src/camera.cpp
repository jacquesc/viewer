#include <glm/gtc/matrix_transform.hpp>

#include <camera.h>

Camera::Camera() : mProjection(1.f) {

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

void Camera::getProjectionMatrix(glm::mat4& projectionMatrix) {
	projectionMatrix = mProjection;
}

void Camera::getViewMatrix(glm::mat4& viewMatrix) {
	// TEMP:
	viewMatrix = glm::lookAt(
    glm::vec3(10,3,10), // Camera is at (4,3,3), in World Space
    glm::vec3(0,0,0), // and looks at the origin
    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
	// viewMatrix = glm::inverse(viewMatrix);
}