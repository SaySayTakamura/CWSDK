#include "TextShape.h"
#include "TextShape.h"
#include "TextShape.h"
#include "TextShape.h"
#include "TextShape.h"
#include "TextShape.h"
#include "../cwsdk.h"

plasma::TextShape::~TextShape()
{
	((void (*)(plasma::TextShape*))CWOffset(0x329730))(this);
}

void plasma::TextShape::Load(bool flag)
{
	((void (*)(plasma::TextShape*, bool))CWOffset(0x368B90))(this, flag);
}

void plasma::TextShape::Draw(plasma::Node* node)
{
	((void (*)(plasma::TextShape*, plasma::Node*))CWOffset(0x368020))(this, node);
}

bool plasma::TextShape::IsPointInsideShape(FloatVector2* vec)
{
	// Pseudo code
	/*
	if (vec->x > this->some_max.x || vec->y > this->some_max.y)
	{
		return false;
	}

	if (vec->x < this->some_min.x || vec->y < this->some_min.x)
	{
		return false;
	}
	return true;
	*/
	return ((bool (*)(plasma::TextShape*, FloatVector2*))CWOffset(0x368430))(this, vec);
}

FloatVector2* plasma::TextShape::GetSomeMaxVector(FloatVector2* vec)
{
	vec->x = this->some_max.x;
	vec->y = this->some_max.y;
	return vec;
}

FloatVector2* plasma::TextShape::GetSomeMinVector(FloatVector2* vec)
{
	vec->x = this->some_min.x;
	vec->y = this->some_min.y;
	return vec;
}

plasma::TextShape* plasma::TextShape::CreateCopy()
{
	return ((plasma::TextShape* (*)(plasma::TextShape*))CWOffset(0x367EA0))(this);
}
