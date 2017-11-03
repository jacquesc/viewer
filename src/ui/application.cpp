#include <nanogui/window.h>

#include <ui/application.h>
#include <renderer.h>
#include <scene.h>

Application::Application() : nanogui::Screen(Eigen::Vector2i(800, 800), "jchu viewer", false) {
	nanogui::Window *window = new nanogui::Window(this, "GLCanvas Demo");

    mRenderer = new Renderer(window);
    mRenderer->setSize({width(), height()});
    mRenderer->renderScene(new Scene());
}

void Application::draw(NVGcontext *ctx) {
	nanogui::Screen::draw(ctx);
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