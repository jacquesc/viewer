#pragma once

#include <nanogui/screen.h>

class Renderer;
class Scene;

class Application : public nanogui::Screen {
public:
	Application();

	void loadObj(const char * const objFile, bool reset = false);

	virtual void draw(NVGcontext *ctx);
	virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);

	virtual bool mouseButtonEvent(const nanogui::Vector2i &p, int button, bool down, int modifiers);
	virtual bool mouseMotionEvent(const nanogui::Vector2i &p, const nanogui::Vector2i &rel, int button, int modifiers);

	virtual bool scrollEvent(const nanogui::Vector2i &p, const nanogui::Vector2f &rel);

private:
	Renderer *mRenderer;
};
