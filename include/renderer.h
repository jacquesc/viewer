#pragma once

#include <nanogui/glcanvas.h>

class Camera;
class Scene;

class Renderer : public nanogui::GLCanvas {
public:
	Renderer(Widget *parent);

	virtual ~Renderer();

	virtual void renderScene(Scene *scene);
	virtual void drawGL();

	Scene *getScene() const { return mScene; } 

private:
	Camera *mCamera;
	Scene *mScene;
};