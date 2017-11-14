#include <iostream>

#include <GLFW/glfw3.h>
#include <nanogui/nanogui.h>

#include <ui/application.h>

int main(int argc, char **argv) {

    nanogui::init();
    {
        nanogui::ref<Application> app = new Application();

        if (argc > 1) {
            app->loadObj(argv[1]);
        }

        app->drawAll();
        app->setVisible(true);
        nanogui::mainloop();
    }

    nanogui::shutdown();
    return 0;
}
