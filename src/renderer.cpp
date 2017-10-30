#include <nanogui/glcanvas.h>

#include <renderer.h>

Renderer::Renderer(Widget *parent) : nanogui::GLCanvas(parent) {

}


Renderer::~Renderer() {
}

void Renderer::drawGL() {
	glClearColor(1.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}