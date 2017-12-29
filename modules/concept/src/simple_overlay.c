#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <dlfcn.h>

#include <stdio.h>
#include <stdbool.h>

/* Declaration variables */
static const char *font_name = "resources/font.ttf";
static FTGLfont *font = NULL;
static const char *hud_message = "Here I should print some useful information.";
static bool toggle = false;

/* Handle elements*/
GLFWkeyfun _cbfun;

void (*_glfwSwapBuffers)() = NULL;
GLFWkeyfun (*_glfwSetKeyCallback)(GLFWwindow *window, GLFWkeyfun cbfun) = NULL;

/* Declaration functions */
static void init () __attribute__((constructor));
void performInput(GLFWwindow* window, int key, int scancode, int action, int mods);
void performOverlay();

/* Implementation */

/**
 * [glfwSwapBuffers Handle call before swap buffers]
 * @param window [description]
 */
void glfwSwapBuffers(GLFWwindow *window)
{
    if (_glfwSwapBuffers == NULL)
    {
        printf("Parsing glfwSwapBuffers...\n");

        void *handle = dlopen("libglfw.so", RTLD_LAZY);
        if (handle)
        {
            printf("Handled glfwSwapBuffers!\n");
            _glfwSwapBuffers = dlsym(handle, "glfwSwapBuffers");
            dlclose(handle);
        }
        else
        {
            printf("Cannot handle glfwSwapBuffers!\n");
        }
    }
    performOverlay();
    _glfwSwapBuffers(window);
}

/**
 * [glfwSetKeyCallback Handle call before set key callback buffers]
 * @param  window [description]
 * @param  cbfun  [description]
 * @return        [description]
 */
GLFWkeyfun glfwSetKeyCallback(GLFWwindow *window, GLFWkeyfun cbfun)
{
    if (_glfwSetKeyCallback == NULL)
    {
        printf("Parsing glfwSetKeyCallback...\n");

        void *handle = dlopen("libglfw.so", RTLD_LAZY);
        if (handle)
        {
            printf("Handled glfwSetKeyCallback!\n");
            _glfwSetKeyCallback = dlsym(handle, "glfwSetKeyCallback");
            dlclose(handle);
        }
        else
        {
            printf("Cannot handle glfwSetKeyCallback!\n");
        }
        /* Initialize HUD variables */
        toggle = true;      /* Active HUD */
    }
    _glfwSetKeyCallback(window, performInput);
    _cbfun = cbfun; /* Store original input callback */
}

void performInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    printf("performInput: %d\n", key);
    _cbfun(window, key, scancode, action, mods);

    if (key == GLFW_KEY_T && action == GLFW_PRESS)
    {
        toggle = !toggle;
        printf("toggle HUD: %d\n", toggle);
    }
}

void performOverlay()
{
    if (font == NULL)
    {
        font = ftglCreateTextureFont(font_name);
        ftglSetFontFaceSize(font, 16, 16);
    }

    if(toggle)
    {
        glColor4f(0, 0, 0, 1);

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(0.0, 800.0, 0.0, 600.0, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(10, 590 - 16, 0.0);

        ftglRenderFont(font, hud_message, FTGL_RENDER_ALL);

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
    }
}
