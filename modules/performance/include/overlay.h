#ifndef OVERLAY_HEADER_FILE_H
#define OVERLAY_HEADER_FILE_H

#include <GLFW/glfw3.h>

class Overlay
{
  public:
    void init();
    void input(GLFWwindow* window, int key, int scancode, int action, int mods);
    void update();
};

#endif  /* OVERLAY_HEADER_FILE_H */
