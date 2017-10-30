#pragma once

#include <nanogui/screen.h>

class Renderer;

class Application : public nanogui::Screen {
public:
	Application();
	virtual void draw(NVGcontext *ctx);

private:
	Renderer *mRenderer;
};