#ifndef PERFORMANCE_OVERLAY_HEADER_FILE_H
#define PERFORMANCE_OVERLAY_HEADER_FILE_H

#include <GLFW/glfw3.h>
#include <FTGL/ftgl.h>

#include <stdio.h>
#include <string>
#include <chrono>

class Overlay
{
private:
    const char *font_name = "resources/font.ttf";
    const char *fps_text = "FPS: ";
    FTGLPixmapFont *font;

    bool toggle_hud = true;

    unsigned int frame_counter = 0;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    std::chrono::duration<double, std::milli> total_time;

    double calculateFPS();
public:
    Overlay();
    bool init();
    void input(GLFWwindow* window, int key, int scancode, int action, int mods);
    void update();

};

#endif  /* PERFORMANCE_OVERLAY_HEADER_FILE_H */
