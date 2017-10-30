#include <nanogui/window.h>

#include <interface/application.h>
#include <renderer.h>

Application::Application() : nanogui::Screen(Eigen::Vector2i(600, 600), "jchu viewer", false) {
	nanogui::Window *window = new nanogui::Window(this, "GLCanvas Demo");

    mRenderer = new Renderer(window);
    mRenderer->setSize({width(), height()});
}

void Application::draw(NVGcontext *ctx) {
	nanogui::Screen::draw(ctx);
}