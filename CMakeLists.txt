cmake_minimum_required (VERSION 2.8.3)
project (jchuviewer)

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
)


# add the executable
add_executable(jchuviewer

# Header files
include/renderer.h
include/interface/application.h

# Source files
src/main.cpp
src/renderer.cpp
src/interface/application.cpp
)

add_definitions(${NANOGUI_EXTRA_DEFS})

target_link_libraries (jchuviewer nanogui ${NANOGUI_EXTRA_LIBS})