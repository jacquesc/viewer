#include <nanogui/glcanvas.h>

#include <camera.h>
#include <renderer.h>
#include <scene.h>

Renderer::Renderer(Widget *parent) : nanogui::GLCanvas(parent) {
	mCamera = new Camera();
	mScene = NULL;
}


Renderer::~Renderer() {
	delete mCamera;
}

void Renderer::renderScene(Scene *scene) {
	mScene = scene;
}

void Renderer::drawGL() {
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (mScene) {
		mScene->draw();
	}
}