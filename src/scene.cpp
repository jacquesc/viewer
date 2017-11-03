#include <iostream>

#include <renderable/renderable.h>
#include <scene.h>

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
		
		Renderable *renderable = new Renderable();
		renderable->setModelData(attributes, shapes);
		mRenderables.push_back(renderable);
		std::cout << "Obj " << objFile << " loaded." << std::endl;

	} else {
		std::cout << objError << std::endl;
	}
	return true;
}

void Scene::clear() {
}

void Scene::draw() {
	std::vector<Renderable *>::iterator it = mRenderables.begin();
	for (; it != mRenderables.end(); ++it) {
		(*it)->draw();
	}
}