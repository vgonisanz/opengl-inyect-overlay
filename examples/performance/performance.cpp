#include <FTGL/ftgl.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

static GLFWwindow *window;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //printf("key_callback: %d\n", key);

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
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
    int result = glfwInit();
    if (result <= 0)
    {
        printf("Aborting execution: Cannot glfwInit with error: %d\n", result);
        exit(EXIT_FAILURE);
    }

    /* Create Window */
    window = glfwCreateWindow(640, 480, "Fake steam game", NULL, NULL);
    if (!window)
    {
        abort_execution("Cannot glfwCreateWindow");
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
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

void changeBackground(float R, float G, float B, float A)
{
    glClearColor(R, G, B, A);
    glClear(GL_COLOR_BUFFER_BIT);
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
    glRotatef(-(float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
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
    changeBackground(0.0f, 0.0f, 0.0f, 1.0f);
    update();

    while(!glfwWindowShouldClose(window))
    {
        drawTriangle();
        update();
    }
    end();
}
