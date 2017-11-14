#include <glsl/presets.h>

namespace {
	// TODO: Export data with cmake build
	const static std::string COLOR_FRAG = "data/shaders/color.frag";
	const static std::string SIMPLE_VERT = "data/shaders/simple.vert";
	const static std::string SIMPLE_LIGHT_VERT = "data/shaders/simplelight.vert";
	const static std::string SIMPLE_LIGHT_FRAG = "data/shaders/simplelight.frag";
}

const std::string& Presets::colorFrag() {
	return COLOR_FRAG;
}

const std::string& Presets::simpleVert() {
	return SIMPLE_VERT;
}

const std::string& Presets::simpleLightVert() {
	return SIMPLE_LIGHT_VERT;
}

const std::string& Presets::simpleLightFrag() {
	return SIMPLE_LIGHT_FRAG;
}
