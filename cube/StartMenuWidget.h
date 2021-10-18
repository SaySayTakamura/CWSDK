#pragma once

#include "BaseWidget.h"

namespace cube {
    class Game;
    class StartMenuWidget : public cube::BaseWidget {
    public:
        enum HoverState : int {
            None = -1,
            StartGame = 0,
            Options = 1,
            Exit = 2,
            Continue = 3,
            Mods = 4,
        };
        cube::Game* game;
        HoverState hover_state;
        int field_1F4;
    };
}

static_assert(sizeof(cube::StartMenuWidget) == 0x1F8, "cube::StartMenuWidget is not the correct size.");