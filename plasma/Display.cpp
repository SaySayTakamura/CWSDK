#include "Display.h"

void plasma::Display::SetVisibility(int frame, int value) {
    this->visibility.data.at(frame) = value;
}

int plasma::Display::GetVisibility(int frame) {
    return this->visibility.data.at(frame);
}

bool plasma::Display::IsVisible()
{
    return this->GetVisibility(this->visibility.current_frame) != 0;
}

int plasma::Display::GetFrameCount() {
    return this->visibility.data.size();
}
