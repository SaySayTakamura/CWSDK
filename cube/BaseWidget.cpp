#include "BaseWidget.h"
#include "../cwsdk.h"

cube::BaseWidget* cube::BaseWidget::ctor(plasma::D3D11Engine* engine, plasma::Node* node, std::wstring* name)
{
	return ((cube::BaseWidget* (*)(cube::BaseWidget*, plasma::D3D11Engine*, plasma::Node*, std::wstring*))CWOffset(0x268A70))(this, engine, node, name);
}

float* cube::BaseWidget::DrawText(FloatVector2* vec, std::wstring* text, float x, float y)
{
	return ((float* (*)(cube::BaseWidget*, FloatVector2*, std::wstring*, float, float))CWOffset(0x269210))(this, vec, text, x, y);
}

void cube::BaseWidget::SetScalableFont(std::wstring* filename)
{
	this->scalable_font = this->d3d11_engine->font_engine->LoadFont(filename);
}

void cube::BaseWidget::SetTextColor(FloatRGBA* color)
{
	this->text_color = *color;
}

void cube::BaseWidget::SetTextColor(char r, char g, char b, char a)
{
	float f_red = (float)r / 255.0;
	float f_green = (float)g / 255.0;
	float f_blue = (float)b / 255.0;
	float f_alpha = (float)a / 255.0;
	FloatRGBA color(f_red, f_green, f_blue, f_alpha);
	this->SetTextColor(&color);
}

void cube::BaseWidget::SetBorderColor(FloatRGBA* color)
{
	this->border_color = *color;
}

void cube::BaseWidget::SetBorderColor(char r, char g, char b, char a)
{
	float f_red = (float)r / 255.0;
	float f_green = (float)g / 255.0;
	float f_blue = (float)b / 255.0;
	float f_alpha = (float)a / 255.0;
	FloatRGBA color(f_red, f_green, f_blue, f_alpha);
	this->SetBorderColor(&color);
}

void cube::BaseWidget::SetTextSize(float size)
{
	this->text_size = size;
}

void cube::BaseWidget::SetBorderSize(float size)
{
	this->border_size = size;
}

void cube::BaseWidget::SetTextPivot(plasma::TextPivot pivot)
{
	this->text_pivot = pivot;
}

FloatVector2* cube::BaseWidget::GetRelativeMousePosition(FloatVector2* vec)
{
	return ((FloatVector2 * (*)(cube::BaseWidget*, FloatVector2*))CWOffset(0x32B180))(this, vec);
}
