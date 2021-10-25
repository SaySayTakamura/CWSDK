#include "Widget.h"
#include <cwsdk.h>

FloatVector2* plasma::Widget::GetSize(FloatVector2* vec)
{
	float x_add = matrix.x_end - matrix.x_begin;
	float y_add = matrix.y_end - matrix.y_begin;
	float v3 = matrix.min_width + x_add;
	float v5 = matrix.max_width + x_add;
	float v4 = matrix.min_height + y_add;
	float v2 = matrix.max_height + y_add;
	
	if (v3 < 0)
	{
		v3 = 0;
	}
	if (v3 > v5)
	{
		v5 = v3;
	}

	if (v2 < 0)
	{
		v2 = 0;
	}

	if (v2 > v4)
	{
		v4 = v2;
	}
	
	vec->x = v5 + matrix.x_begin - matrix.x_end;
	vec->y = v4 + matrix.y_begin - matrix.y_end;
	return vec;
	//return ((FloatVector2* (*)(plasma::Widget*, FloatVector2*))CWOffset(0x32A110))(this, vec);
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

plasma::Widget* plasma::Widget::CreateCopy(Node* node)
{
	return ((plasma::Widget * (*)(plasma::Widget*, plasma::Node*))CWOffset(0x32A2C0))(this, node);
}

plasma::Widget* plasma::Widget::Copy(Widget* src, Node* node)
{
	return ((plasma::Widget* (*)(plasma::Widget*, plasma::Widget*, plasma::Node*))CWOffset(0x329210))(this, src, node);
}
