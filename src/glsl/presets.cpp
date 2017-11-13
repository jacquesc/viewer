#include <glsl/presets.h>

namespace {
	// TODO: Export data with cmake build
	const static std::string COLOR_FRAG = "../data/shaders/color.frag";
	const static std::string SIMPLE_VERT = "../data/shaders/simple.vert"; 
}

const std::string& Presets::colorFrag() {
	return COLOR_FRAG;
}
const std::string& Presets::simpleVert() {
	return SIMPLE_VERT;
}