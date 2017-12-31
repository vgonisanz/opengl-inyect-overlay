#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#include <glfwParser.h>

// int 	glfwInit (void)
// Window *window = new Window(this, "Button demo");
//         window->setPosition(Vector2i(15, 15));
//         window->setLayout(new GroupLayout());

void performOverlay()
{
    //printf("performOverlay\n");
}

int glfwInit(void)
{
    printf("glfwInit detected, trying to parse functions...\n");

    const char *glfw_library_name = "libglfw.so";
    const char *glfw_library_name_invent = "libglfwinvent.so";
    
    (void)glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwInit), glfw_library_name, "glfwInit");
    (void)glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwSwapBuffers), glfw_library_name, "glfwSwapBuffers");

    glfwParser::_glfwInit();    /* Continue with normal glfw init */
}

void glfwSwapBuffers(GLFWwindow *window)
{
    performOverlay();
    glfwParser::_glfwSwapBuffers(window);
}
