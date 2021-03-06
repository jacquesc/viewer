cmake_minimum_required (VERSION 2.8.3)
project (jchu_glviewer)

add_subdirectory(ext ext_build)

include_directories(
  # Nori include files
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  # Eigen linear algebra library
  ${EIGEN_INCLUDE_DIR}
  # GLFW library for OpenGL context creation
  ${GLFW_INCLUDE_DIR}
  # GLEW library for accessing OpenGL functions
  ${GLEW_INCLUDE_DIR}
  # NanoGUI user interface library
  ${NANOGUI_INCLUDE_DIR}
  ${NANOGUI_EXTRA_INCS}
  # Tinyobjloader
  ${TINYOBJLOADER_INCLUDE_DIR}
)


# add the executable
add_executable(jchu_glviewer

# Header files
#include/camera.h
include/ui/application.h
include/renderable/renderable.h
include/renderer.h
include/scene.h
include/gl/glrenderable.h
include/gl/shaderfactory.h
include/gl/glhandle.h
include/gl/shaderprogram.h
include/glsl/shaderprogram/simplecolor.h
include/glsl/shaderprogram/simplecolor.h

ext/trackball.h

# Source files
src/camera.cpp
src/main.cpp
src/renderable/renderable.cpp
src/renderer.cpp
src/scene.cpp
src/ui/application.cpp
src/gl/glrenderable.cpp
src/gl/shaderfactory.cpp
src/gl/shaderprogram.cpp
src/glsl/presets.cpp
src/glsl/simplecolor.cpp
src/glsl/simplelight.cpp

ext/trackball.cc

)

add_definitions(${NANOGUI_EXTRA_DEFS})

target_link_libraries (jchu_glviewer glm nanogui tinyobjloader ${NANOGUI_EXTRA_LIBS})