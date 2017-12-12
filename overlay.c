#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <dlfcn.h>

#include <stdio.h>

/* Declaration variables */
static const char *font_name = "resources/font.ttf";
static FTGLfont *font = NULL;
void (*_glfwSwapBuffers)() = NULL;

/* Declaration functions */
static void init () __attribute__((constructor));
void performOverlay();

/* Implementation */
void glfwSwapBuffers(GLFWwindow *window)
{
    if (_glfwSwapBuffers == NULL)
    {
        printf("Parsing glfwSwapBuffers...\n");

        void *handle = dlopen("libglfw.so", RTLD_LAZY);
        if (handle)
        {
            printf("Handled!\n");
            _glfwSwapBuffers = dlsym(handle, "glfwSwapBuffers");
            dlclose(handle);
        }
        else
        {
            printf("Cannot handle!\n");
        }
    }

    performOverlay();
    _glfwSwapBuffers(window);
}

void performOverlay()
{
    if (font == NULL)
    {
        font = ftglCreateTextureFont(font_name);
        ftglSetFontFaceSize(font, 16, 16);
    }

    glColor4f(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 800.0, 0.0, 600.0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(10, 590 - 16, 0.0);

    ftglRenderFont(font, "Here I should print some useful information.", FTGL_RENDER_ALL);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
}
