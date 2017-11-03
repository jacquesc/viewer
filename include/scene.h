#pragma once

#include <vector>

class Renderable;

class Scene {
public:
	Scene();
	virtual ~Scene();

	bool addObjModel(const char * const objFile);
	void clear();


	void draw();
	
private:
	std::vector<Renderable *> mRenderables;
};