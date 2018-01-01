#include <overlay.h>

Overlay::Overlay()
{

}

bool Overlay::init()
{
    printf("Creating font...\n");
    this->font = new FTPixmapFont(this->font_name);
    if(this->font->Error())
    {
        printf("Error creating font\n");
        return false;
    }
    this->font->FaceSize(16);

    printf("Starting FPS time counter...\n");
    frame_counter = 0;
    this->start = std::chrono::system_clock::now();
    this->end = std::chrono::system_clock::now();
    return true;
}

void Overlay::input(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_T && action == GLFW_PRESS)
    {
        this->toggle_hud = !this->toggle_hud;
        printf("toggle HUD: %d\n", this->toggle_hud);
    }
}

void Overlay::update()
{
    //printf("update\n");
    frame_counter++;

    if(this->toggle_hud)
    {
        glColor4f(0, 0, 0, 1);

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(0.0, 800.0, 0.0, 600.0, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(10, 590 - 16, 0.0);

        std::string message = this->fps_text + std::to_string(calculateFPS());
        this->font->Render(message.c_str());

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
    }
    this->start = std::chrono::system_clock::now();
}

double Overlay::calculateFPS()
{
    this->end = std::chrono::system_clock::now();
    this->total_time += this->end - this->start;
    if(this->total_time.count() == 0)
        return 0;
    return (double)(this->frame_counter / this->total_time.count())*1000;
}
