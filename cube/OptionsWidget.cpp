#include "OptionsWidget.h"
#include "cwsdk.h"

cube::OptionsWidget* cube::OptionsWidget::ctor(cube::Game* game, plasma::Node* blackwidget, plasma::Node* left_button, plasma::Node* right_button, plasma::Node* button2)
{
    return ((cube::OptionsWidget* (*)(cube::OptionsWidget*, cube::Game*, plasma::Node*, plasma::Node*, plasma::Node*, plasma::Node*))CWOffset(0x287050))(this, game, blackwidget, left_button, right_button, button2);
}
