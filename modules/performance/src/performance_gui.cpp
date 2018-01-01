#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <performance_gui.h>
#include <glfwParser.h>
#include <overlay.h>

Overlay ui;

const char *glfw_library_name = "libglfw.so";

int glfwInit(void)
{
    printf("Initialize original glfwInit...\n");

    if(!glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwInit), glfw_library_name, "glfwInit")) return -1;

    if(GLFW_FALSE == glfwParser::_glfwInit())
    {
        printf("Error in original glfwInit\n");
        return GLFW_FALSE;
    }
    printf("glfwInit completed!, trying to parse functions...\n");

    if(!glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwSetKeyCallback), glfw_library_name, "glfwSetKeyCallback")) return -2;
    if(!glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwSwapBuffers), glfw_library_name, "glfwSwapBuffers")) return -3;

    ui.init();
    return GLFW_TRUE;
}

GLFWkeyfun glfwSetKeyCallback(GLFWwindow *window, GLFWkeyfun cbfun)
{
    printf("Setting our keycallback instead original...");
    glfwParser::_glfwSetKeyCallback(window, performInput);
    glfwParser::_GLFWkeyfun = cbfun;                            /* Store original input callback */
}

void glfwSwapBuffers(GLFWwindow *window)
{
    ui.update();
    glfwParser::_glfwSwapBuffers(window);
}

void performInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    printf("performInput: %d\n", key);
    //ui.input();
    glfwParser::_GLFWkeyfun(window, key, scancode, action, mods);
}
