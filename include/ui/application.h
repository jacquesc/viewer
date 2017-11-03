#pragma once

#include <nanogui/screen.h>

class Renderer;
class Scene;

class Application : public nanogui::Screen {
public:
	Application();
	virtual void draw(NVGcontext *ctx);

	void loadObj(const char * const objFile, bool reset = false);

private:
	Renderer *mRenderer;
};