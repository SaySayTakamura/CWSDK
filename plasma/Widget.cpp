#include "Widget.h"
#include <cwsdk.h>

FloatVector2* plasma::Widget::GetSomeVector2(FloatVector2* vec)
{
	return ((FloatVector2* (*)(plasma::Widget*, FloatVector2*))CWOffset(0x32D010))(this, vec);
}

FloatVector2* plasma::Widget::GetSize(FloatVector2* vec)
{
	/*float x_add = matrix._21 - matrix._31;
	float y_add = matrix._22 - matrix._32;
	float v3 = matrix._43 + x_add;
	float v5 = matrix._41 + x_add;
	float v4 = matrix._44 + y_add;
	float v2 = matrix._42 + y_add;
	
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
	
	vec->x = v5 + matrix._31 - matrix._21;
	vec->y = v4 + matrix._32 - matrix._22;
	return vec;*/
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

void plasma::Widget::SetSize(FloatVector2* vec)
{
	this->SetSize(vec->x, vec->y);
}

void plasma::Widget::SetSize(float x, float y)
{
	/*
	this->matrix.m[0] = 0;
	this->matrix.m[1] = 0;
	this->matrix.m[4] = (1 / 3.0f) * (200 - x);
	this->matrix.m[8] = 200 - x;
	this->matrix.m[5] = (1 / 3.0f) * (200 - y);
	this->matrix.m[9] = 200 - y;
	*/
	this->matrix.m[12] = x;
	this->matrix.m[13] = y;
}

void plasma::Widget::Translate(FloatVector2* vec, int flags)
{
	((void (*)(plasma::Widget*, FloatVector2*, int))CWOffset(0x32C6F0))(this, vec, flags);
}

void plasma::Widget::Translate(float x, float y, int flags)
{
	FloatVector2 vec(x, y);
	this->Translate(&vec, flags);
}

bool plasma::Widget::IsSquareHovered(FloatVector2* mouse, int x, int y, int width, int height)
{
	if (mouse->x < x || mouse->x > x + width || mouse->y < y || mouse->y > y + height)
	{
		return false;
	}
	return true;
}

void plasma::Widget::CW_32B0C0()
{
	((void (*)(plasma::Widget*))CWOffset(0x32B0C0))(this);
}

plasma::Widget* plasma::Widget::CreateCopy(Node* node)
{
	return ((plasma::Widget * (*)(plasma::Widget*, plasma::Node*))CWOffset(0x32A2C0))(this, node);
}

plasma::Widget* plasma::Widget::Copy(Widget* src, Node* node)
{
	return ((plasma::Widget* (*)(plasma::Widget*, plasma::Widget*, plasma::Node*))CWOffset(0x329210))(this, src, node);
}

void plasma::Widget::Draw()
{
}

void* plasma::Widget::F_0x10(void* a1)
{
	return a1;
}

void* plasma::Widget::F_0x18(void* a1)
{
	return a1;
}

bool plasma::Widget::F_0x20()
{
	return false;
}

bool plasma::Widget::F_0x28()
{
	return false;
}

void plasma::Widget::F_0x30()
{
}

void plasma::Widget::F_0x38()
{
	((void (*)(plasma::Widget*))CWOffset(0x32B830))(this);
}

void plasma::Widget::F_0x40()
{
	((void (*)(plasma::Widget*))CWOffset(0x32BFD0))(this);
}

void plasma::Widget::F_0x48(FloatVector2* vec1, FloatVector2* vec2)
{
	((void (*)(plasma::Widget*, FloatVector2*, FloatVector2*))CWOffset(0x32BD70))(this, vec1, vec2);
}

void plasma::Widget::F_0x50()
{
}

void plasma::Widget::F_0x58()
{
	((void (*)(plasma::Widget*))CWOffset(0x32B990))(this);
}

void plasma::Widget::plasma__Widget__cw_32BB40()
{
}

void plasma::Widget::nullsub_3()
{
}

void plasma::Widget::nullsub_4()
{
}

void plasma::Widget::nullsub_5()
{
}

void plasma::Widget::nullsub_6()
{
}

void plasma::Widget::nullsub_7()
{
}

void plasma::Widget::nullsub_8()
{
}

void plasma::Widget::nullsub_9()
{
}

void plasma::Widget::nullsub_10()
{
}

void plasma::Widget::OnMouseOver()
{
	((void (*)(plasma::Widget*))CWOffset(0x32BB80))(this);
}

void plasma::Widget::nullsub_11()
{
}

void plasma::Widget::nullsub_12()
{
}

void plasma::Widget::nullsub_13()
{
}

void plasma::Widget::nullsub_14()
{
}

void plasma::Widget::nullsub_15()
{
}

void plasma::Widget::nullsub_16()
{
}

void plasma::Widget::nullsub_17()
{
}

void plasma::Widget::nullsub_18()
{
}

void plasma::Widget::nullsub_19()
{
}

void plasma::Widget::nullsub_20()
{
}

void plasma::Widget::nullsub_21()
{
}

void plasma::Widget::nullsub_22()
{
}

void plasma::Widget::nullsub_23()
{
}

void plasma::Widget::plasma__Widget__cw_32B5A0()
{
	((void (*)(plasma::Widget*))CWOffset(0x32B5A0))(this);
}

void plasma::Widget::plasma__Widget__cw_32B6B0()
{
	((void (*)(plasma::Widget*))CWOffset(0x32B6B0))(this);
}

void plasma::Widget::nullsub_24()
{
}

void plasma::Widget::nullsub_25()
{
}

void plasma::Widget::plasma__Widget__cw_32B6E0()
{
	((void (*)(plasma::Widget*))CWOffset(0x32B6E0))(this);
}

plasma::Widget* plasma::Widget::CreateCopy()
{
	((plasma::Widget * (*)(plasma::Widget*))CWOffset(0x32A2C0))(this);
}

void plasma::Widget::plasma__Widget__cw_32A8D0(bool enable)
{
	((void (*)(plasma::Widget*, bool))CWOffset(0x32A8D0))(this, enable);
}

void plasma::Widget::nullsub_26()
{
}
