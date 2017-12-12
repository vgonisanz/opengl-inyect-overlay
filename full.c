#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

static const char *font_name = "resources/font.ttf";

static GLFWwindow *window;
static FTGLfont *font = NULL;

static bool wait_enter = true;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    printf("key_callback: %d\n", key);

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        wait_enter = false;
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

static void abort_execution(const char *abort_message)
{
    printf("Aborting execution: %s", abort_message);
    glfwTerminate();
    exit(EXIT_FAILURE);
}

static void initialize()
{
    printf("Initializing...\n");

    /* Callback error */
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    {
        printf("Aborting execution: Cannot glfwInit");
        exit(EXIT_FAILURE);
    }

    /* Create Window */
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        abort_execution("Cannot glfwCreateWindow");
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    /* Create Font */
    font = ftglCreateTextureFont(font_name);
    ftglSetFontFaceSize(font, 16, 16);

    if (font == NULL)
    {
        abort_execution("Cannot ftglCreateTextureFont");
    }
}

static void update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

static void end()
{
    printf("Cleaning up.\n");
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

/* No work right now */
static void wait_enter_event()
{
    while(wait_enter)
    {
        usleep(1000);
    }
}

void changeBackground(float R, float G, float B, float A)
{
    glClearColor(R, G, B, A);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawMessage()
{
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

void drawTriangle()
{
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}

int main(void)
{
    initialize();
    changeBackground(1.0f, 0.0f, 0.0f, 1.0f);
    update();

    //wait_enter_event(); /* bad */

    //changeBackground(0.0f, 0.0f, 0.0f, 1.0f);

    while(!glfwWindowShouldClose(window))
    {
        drawTriangle();
        drawMessage();
        update();
    }
    end();
}
