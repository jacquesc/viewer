#pragma once

#include <vector>

class Camera;
class Renderable;

class Scene {
public:
	Scene();
	virtual ~Scene();

	bool addObjModel(const char * const objFile);
	void clear();

	void setupCamera(Camera * camera);
	void draw(Camera *camera);
	
private:
	std::vector<Renderable *> mRenderables;
};