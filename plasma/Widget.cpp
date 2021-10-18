#include "Widget.h"
#include <cwsdk.h>

FloatVector2* plasma::Widget::GetSize(FloatVector2* vec)
{
	return ((FloatVector2* (*)(plasma::Widget*, FloatVector2*))CWOffset(0x32A110))(this, vec);
}

float plasma::Widget::GetXSize()
{
	FloatVector2 vec2;
	return this->GetSize(&vec2)->x;
}

float plasma::Widget::GetYSize()
{
	FloatVector2 vec2;
	return this->GetSize(&vec2)->y;
}
