#include "StartMenuWidget.h"
#include "cwsdk.h"

cube::StartMenuWidget* cube::StartMenuWidget::ctor(cube::Game* game, plasma::Node* node)
{
	return ((cube::StartMenuWidget*(*)(cube::StartMenuWidget*, cube::Game*, plasma::Node*))CWOffset(0x2910C0))(this, game, node);
}