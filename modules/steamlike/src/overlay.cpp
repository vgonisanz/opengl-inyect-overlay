#include <overlay.h>

#include <stdio.h>

#include <nanogui/window.h>

void Overlay::init()
{
    printf("init\n");

    using namespace nanogui;
    // Window *window = new Window(this, "Button demo");
    //         window->setPosition(Vector2i(15, 15));
    //         window->setLayout(new GroupLayout());
}

void Overlay::input(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

void Overlay::update()
{
    //printf("update\n");
}
