#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <steam_gui.h>
#include <glfwParser.h>

// int 	glfwInit (void)
// Window *window = new Window(this, "Button demo");
//         window->setPosition(Vector2i(15, 15));
//         window->setLayout(new GroupLayout());

const char *glfw_library_name = "libglfw.so";

int glfwInit(void)
{
    printf("Initialize original glfwInit...\n");

    (void)glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwInit), glfw_library_name, "glfwInit");

    glfwParser::_glfwInit();

    printf("glfwInit completed!, trying to parse functions...\n");

    (void)glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwSetKeyCallback), glfw_library_name, "glfwSetKeyCallback");
    (void)glfwParser::parseFunction(reinterpret_cast<void **>(&glfwParser::_glfwSwapBuffers), glfw_library_name, "glfwSwapBuffers");

    /* How check if init ok without check everytime??? */
}

GLFWkeyfun glfwSetKeyCallback(GLFWwindow *window, GLFWkeyfun cbfun)
{
    printf("Setting our keycallback instead original...");
    glfwParser::_glfwSetKeyCallback(window, performInput);
    glfwParser::_GLFWkeyfun = cbfun;                            /* Store original input callback */
}

void glfwSwapBuffers(GLFWwindow *window)
{
    performOverlay();
    glfwParser::_glfwSwapBuffers(window);
}

void performInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    printf("performInput: %d\n", key);
    glfwParser::_GLFWkeyfun(window, key, scancode, action, mods);
}

void performOverlay()
{
    //printf("performOverlay\n");
}
