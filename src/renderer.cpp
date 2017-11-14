#include <nanogui/glcanvas.h>

#include <camera.h>
#include <renderer.h>
#include <scene.h>

extern void trackball(float q[4], float p1x, float p1y, float p2x, float p2y);
extern void add_quats(float *q1, float *q2, float *dest);
extern void build_rotmatrix(float m[4][4], const float q[4]);

namespace {
	const float ROTATION_FACTOR = 1.f;
	const float TRANSLATION_FACTOR = 0.5f;
}

Renderer::Renderer(Widget *parent, size_t width, size_t height)
	: nanogui::GLCanvas(parent),
	  mScreenDim(width, height),
	  mMouseLeftPressed(false) {

	mCamera = new Camera();
	mScene = NULL;
	trackball(mCurrentQuat, 0, 0, 0, 0);
}

Renderer::~Renderer() {
	delete mCamera;
}

void Renderer::renderScene(Scene *scene) {
	mScene = scene;
	std::cout << "Setting up camera.." << std::endl;
	mScene->setupCamera(mCamera);
}

void Renderer::drawGL() {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (mScene) {
		mScene->draw(mCamera);
	}
}

bool Renderer::mouseButtonEvent(const nanogui::Vector2i &p, int button, bool down, int modifiers) {
	if (button == GLFW_MOUSE_BUTTON_1) {
		mMouseLeftPressed = down;
		trackball(mPrevQuat, 0.0, 0.0, 0.0, 0.0);
	}
	return true;
}

bool Renderer::mouseMotionEvent(const nanogui::Vector2i &p, const nanogui::Vector2i &rel, int button, int modifiers) {
	if (mMouseLeftPressed) {
	    trackball(mPrevQuat, ROTATION_FACTOR * (2.0f * p.x() - mScreenDim.x()) / (float)mScreenDim.x(),
	    		ROTATION_FACTOR * (mScreenDim.y() - 2.0f * mLastMousePos.y()) / (float)mScreenDim.y(),
				ROTATION_FACTOR * (2.0f * p.x()- mScreenDim.x()) / (float)mScreenDim.x(),
				ROTATION_FACTOR * (mScreenDim.y() - 2.0f * p.y()) / (float)mScreenDim.y());

	    add_quats(mPrevQuat, mCurrentQuat, mCurrentQuat);
	    build_rotmatrix(mTrackballMatrix, mCurrentQuat);
	    mCamera->updateTrackball(mTrackballMatrix);
	}

	mLastMousePos.x() = p.x();
	mLastMousePos.y() = p.y();
}

bool Renderer::scrollEvent(const nanogui::Vector2i &p, const nanogui::Vector2f &rel) {
	mCamera->zoom(TRANSLATION_FACTOR * rel.y());
	return true;
}

bool Renderer::keyboardEvent(int key, int scancode, int action, int modifiers) {
	return true;
}
