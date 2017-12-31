#ifndef STEAMGUI_HEADER_FILE_H
#define STEAMGUI_HEADER_FILE_H

#include <stdio.h>

int glfwInit(void);
GLFWkeyfun glfwSetKeyCallback(GLFWwindow *window, GLFWkeyfun cbfun);
void performInput(GLFWwindow* window, int key, int scancode, int action, int mods);
void glfwSwapBuffers(GLFWwindow *window);

void performOverlay();
void performInput(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif  /* STEAMGUI_HEADER_FILE_H */
