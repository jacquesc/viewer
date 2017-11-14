#pragma once

#include <nanogui/glcanvas.h>

class Camera;
class Scene;

class Renderer : public nanogui::GLCanvas {
public:
	Renderer(Widget *parent, size_t width, size_t height);

	virtual ~Renderer();
	virtual void renderScene(Scene *scene);
	virtual void drawGL();

	virtual bool mouseButtonEvent(const nanogui::Vector2i &p, int button, bool down, int modifiers);
	virtual bool mouseMotionEvent(const nanogui::Vector2i &p, const nanogui::Vector2i &rel, int button, int modifiers);
	bool scrollEvent(const nanogui::Vector2i &p, const nanogui::Vector2f &rel);
	virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);

	Scene *getScene() const { return mScene; } 

private:
	Camera *mCamera;
	Scene *mScene;

	nanogui::Vector2i mScreenDim;

	float mPrevQuat[4];
	float mCurrentQuat[4];
	float mTrackballMatrix[4][4];

	nanogui::Vector2i mLastMousePos;
	bool mMouseLeftPressed;

};
