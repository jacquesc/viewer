#include <iostream>

#include <camera.h>
#include <gl/glrenderable.h>
#include <glsl/presets.h>
#include <scene.h>

namespace {
	static const Presets::Shaders DEFAULT_SHADING = Presets::SIMPLE_LIGHT;
}

Scene::Scene() {
}

Scene::~Scene() {
	for (size_t i = 0; i < mRenderables.size(); i++) {
		delete mRenderables[i];
		mRenderables[i] = NULL;
	}
	mRenderables.clear();
}

bool Scene::addObjModel(const char * const objFile) {
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string objError;
	tinyobj::attrib_t attributes;

	if (tinyobj::LoadObj(&attributes, &shapes, &materials, &objError, objFile)) {
		std::cout << "Obj " << objFile << " loaded." << std::endl;
		// FIXME: set which type don't hardcode, read from "scene" file if specified
		GLRenderable *renderable = new GLRenderable(DEFAULT_SHADING);
		renderable->setModelData(attributes, shapes);
		mRenderables.push_back(renderable);

	} else {
		std::cout << objError << std::endl;
	}
	return true;
}

void Scene::clear() {
}

void Scene::setupCamera(Camera *camera) {
	// FIXME: Remove hard-coded values
	camera->setCameraSettings(45.f, 1.f, 0.1f, 100.f);
}

void Scene::draw(Camera *camera) {
	glEnable(GL_DEPTH_TEST);
	
	setupCamera(camera);

	std::vector<Renderable *>::iterator it = mRenderables.begin();
	for (; it != mRenderables.end(); ++it) {
		(*it)->draw(camera);
	}
}
