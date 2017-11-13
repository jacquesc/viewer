#pragma once

#include <string>

struct Presets {

	enum Shaders {
		SIMPLE_COLOR,
		SIMPLE_LIGHT
	};

	static const std::string& colorFrag();
	static const std::string& simpleVert();
	static const std::string& simpleLightVert();
	static const std::string& simpleLightFrag();
};