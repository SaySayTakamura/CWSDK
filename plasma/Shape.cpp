#include "Shape.h"
#include "../cwsdk.h"

plasma::Shape::~Shape()
{
    ((void (*)(plasma::Shape*))CWOffset(0x38CFD0))(this);
}

void plasma::Shape::Load(bool flag) {}

void plasma::Shape::Draw(plasma::Node* node)
{
}

bool plasma::Shape::v_0x18(FloatVector2* vec, void* unk_type, Matrix4* m1, Matrix4* m2)
{
    return false;
}

bool plasma::Shape::IsPointInsideShape(FloatVector2* vec)
{
    return false;
}

bool plasma::Shape::v_0x28()
{
    return true;
}

FloatVector2* plasma::Shape::GetSomeMaxVector(FloatVector2* vec)
{
    return ((FloatVector2* (*)(plasma::Shape*, FloatVector2*))CWOffset(0x26A720))(this, vec);
}

FloatVector2* plasma::Shape::GetSomeMinVector(FloatVector2* vec)
{
    return ((FloatVector2* (*)(plasma::Shape*, FloatVector2*))CWOffset(0x26A720))(this, vec);
}

bool plasma::Shape::v_0x40()
{
    return false;
}

bool plasma::Shape::v_0x48()
{
    return false;
}

void plasma::Shape::v_0x50()
{
}

void plasma::Shape::v_0x58()
{
}

void plasma::Shape::v_0x60()
{
}

plasma::Shape* plasma::Shape::CreateCopy()
{
    return nullptr;
}

void plasma::Shape::SomeFontFunction(void* unk_type)
{
}

void plasma::Shape::v_0x78()
{
}

void plasma::Shape::v_0x80()
{
}

bool plasma::Shape::v_0x88()
{
    return false;
}

void plasma::Shape::v_0x90()
{
}
