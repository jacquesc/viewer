#pragma once

#include <nanogui/glcanvas.h>

class Renderer : public nanogui::GLCanvas {
public:
	Renderer(Widget *parent);

	virtual ~Renderer();

	virtual void drawGL();
};