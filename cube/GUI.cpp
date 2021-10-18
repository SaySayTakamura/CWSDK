#include "GUI.h"
#include "../cwsdk.h"

void cube::GUI::UpdateResolution(signed int width, signed int height) {
    ((void(*)(cube::GUI*, signed int, signed int))CWOffset(0x101BD0))(this, width, height);
}

void cube::GUI::SomethingWithStartMenuGUISelection(cube::StartMenuWidget* widget, int x, int y)
{
    ((void(*)(cube::GUI*, cube::StartMenuWidget*, signed int, signed int))CWOffset(0xF97E0))(this, widget, x, y);
}

/* Careful, this crashes for some reason... whilst the calls are correct.*/
void cube::GUI::MouseUp(int btn)
{
    if (btn == cube::MouseButton::MiddleMouseButton)
    {
        this->game->plasma_engine->MiddleMouseButtonUp();
    }
    else if (btn == cube::MouseButton::LeftMouseButton)
    {
        this->game->plasma_engine->LeftMouseButtonUp();
    }
    else if (btn == cube::MouseButton::RightMouseButton)
    {
        this->game->plasma_engine->RightMouseButtonUp();
    }
    return;
}
