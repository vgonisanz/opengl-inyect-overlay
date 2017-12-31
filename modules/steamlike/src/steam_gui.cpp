#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <dlfcn.h>

#include <stdio.h>

typedef void (*swapBuffersFunction)(GLFWwindow *window);

static swapBuffersFunction _glfwSwapBuffers = nullptr;

// Window *window = new Window(this, "Button demo");
//         window->setPosition(Vector2i(15, 15));
//         window->setLayout(new GroupLayout());

void performOverlay()
{
    printf("performOverlay\n");
}

bool parseFunction(void **original_pointer_to_function, const char *library_name, int flags, const char *symbol)
{
    if (*original_pointer_to_function == nullptr)
    {
        printf("Parsing %s...\n", symbol);

        void *handle = dlopen(library_name, flags);
        if (handle)
        {
            printf("Handled %s!\n", symbol);
            void *symbol_pointer = dlsym(handle, symbol);
            *original_pointer_to_function = reinterpret_cast<void *>(symbol_pointer);
            dlclose(handle);
        }
        else
        {
            printf("Cannot handle %s!\n", symbol);
            return false;
        }
        return true;
    }
    return false;
}

void glfwSwapBuffers(GLFWwindow *window)
{
    (void)parseFunction(reinterpret_cast<void **>(&_glfwSwapBuffers), "libglfw.so", RTLD_LAZY, "glfwSwapBuffers");
    performOverlay();
    _glfwSwapBuffers(window);
}
