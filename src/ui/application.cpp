#include <nanogui/window.h>

#include <ui/application.h>
#include <renderer.h>
#include <scene.h>

namespace {
	const static int INIT_WIDTH = 800;
	const static int INIT_HEIGHT = 800;
}

Application::Application() : nanogui::Screen(Eigen::Vector2i(INIT_WIDTH, INIT_HEIGHT), "jchu viewer", false) {
	nanogui::Window *window = new nanogui::Window(this, "GLCanvas Demo");

    mRenderer = new Renderer(window, INIT_WIDTH, INIT_HEIGHT);
    mRenderer->setSize({width(), height()});
    mRenderer->renderScene(new Scene());
}

void Application::loadObj(const char * const objFile, bool reset) {
	Scene* scene = mRenderer->getScene();
	if (scene) {
		if (reset) {
			scene->clear();
		}
		scene->addObjModel(objFile);
	} else {
		std::cerr << "Invalid scene" << std::endl;
	}
}

void Application::draw(NVGcontext *ctx) {
	nanogui::Screen::draw(ctx);
}

bool Application::keyboardEvent(int key, int scancode, int action, int modifiers) {
	return true;
}

bool Application::mouseButtonEvent(const nanogui::Vector2i &p, int button, bool down, int modifiers) {
	mRenderer->mouseButtonEvent(p, button, down, modifiers);
	return true;
}

bool Application::mouseMotionEvent(const nanogui::Vector2i &p, const nanogui::Vector2i &rel, int button, int modifiers) {
	mRenderer->mouseMotionEvent(p, rel, button, modifiers);
	return true;
}

bool Application::scrollEvent(const nanogui::Vector2i &p, const nanogui::Vector2f &rel) {
	mRenderer->scrollEvent(p, rel);
	return true;
}
