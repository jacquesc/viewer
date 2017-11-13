#pragma once

#include <string>

struct Presets {

	enum Shaders {
		SIMPLE_COLOR,
		SIMPLE_LIGHTING
	};

	static const std::string& colorFrag();
	static const std::string& simpleVert();
};