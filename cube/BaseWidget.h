#pragma once

#include "../plasma/Widget.h"
#include "../plasma/ScalableFont.h"
#include "../common/Vector2.h"
#include "../common/RGBA.h"

namespace cube {
	enum TextPivot : int {
		Left = 0,
		Center,
		Right
	};

	class BaseWidget : public plasma::Widget {
	public:
		plasma::ScalableFont* scalable_font;
		float text_size;
		float border_size;
		float field_1B8;
		float field_1BC;
		float field_1C0;
		FloatRGBA text_color;
		FloatRGBA border_color;
		TextPivot text_pivot;

		BaseWidget* ctor(plasma::D3D11Engine* engine, plasma::Node* node, std::wstring* name);

		float* DrawText(FloatVector2* vec, std::wstring* text, float x, float y);
		void SetScalableFont(std::wstring* filename);
		void SetTextColor(FloatRGBA* color);
		void SetTextColor(char r, char g, char b, char a = 255);
		void SetBorderColor(FloatRGBA* color);
		void SetBorderColor(char r, char g, char b, char a = 255);
		void SetTextSize(float size);
		void SetBorderSize(float size);
		void SetTextPivot(TextPivot pivot);
		FloatVector2* GetRelativeMousePosition(FloatVector2* vec);
	};
}


static_assert(sizeof(cube::BaseWidget) == 0x1E8, "cube::BaseWidget is not the correct size.");