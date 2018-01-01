#ifndef GLFWPARSER_HEADER_FILE_H
#define GLFWPARSER_HEADER_FILE_H

#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

namespace glfwParser
{
    typedef int (*glfwInitFunction)(void);
    typedef void (*glfwSwapBuffersFunction)(GLFWwindow *window);
    typedef GLFWkeyfun (*glfwSetKeyCallbackFunction)(GLFWwindow *window, GLFWkeyfun cbfun);
    typedef void (*GLFWkeyfunFunction)(GLFWwindow *, int key, int scancode, int action, int mods);

    static glfwInitFunction _glfwInit = nullptr;
    static glfwSwapBuffersFunction _glfwSwapBuffers = nullptr;
    static glfwSetKeyCallbackFunction _glfwSetKeyCallback = nullptr;
    static GLFWkeyfunFunction _GLFWkeyfun = nullptr;

    bool parseFunction(void **original_pointer_to_function, const char *library_name, const char *symbol);
}

#endif  /* GLFWPARSER_HEADER_FILE_H */
