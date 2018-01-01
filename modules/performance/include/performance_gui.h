#ifndef STEAMGUI_HEADER_FILE_H
#define STEAMGUI_HEADER_FILE_H

#include <stdio.h>

/* GLFW Functions */
int glfwInit(void);
GLFWkeyfun glfwSetKeyCallback(GLFWwindow *window, GLFWkeyfun cbfun);
void performInput(GLFWwindow* window, int key, int scancode, int action, int mods);
void glfwSwapBuffers(GLFWwindow *window);

#endif  /* STEAMGUI_HEADER_FILE_H */
