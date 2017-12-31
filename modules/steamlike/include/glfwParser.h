#ifndef GLFWPARSER_HEADER_FILE_H
#define GLFWPARSER_HEADER_FILE_H

#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

namespace glfwParser
{
    typedef int (*initFunction)(void);
    typedef void (*swapBuffersFunction)(GLFWwindow *window);

    static initFunction _glfwInit = nullptr;
    static swapBuffersFunction _glfwSwapBuffers = nullptr;

    bool parseFunction(void **original_pointer_to_function, const char *library_name, const char *symbol);
}

#endif  /* GLFWPARSER_HEADER_FILE_H */
