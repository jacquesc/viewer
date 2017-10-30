#include <iostream>

#include <GLFW/glfw3.h>
#include <nanogui/nanogui.h>

#include <interface/application.h>

int main(int argc, char **argv) {

    nanogui::init();

    {
        nanogui::ref<Application> app = new Application();
        app->drawAll();
        app->setVisible(true);
        nanogui::mainloop();
    }

    nanogui::shutdown();
    return 0;
}