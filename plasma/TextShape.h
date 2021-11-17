#pragma once

#include "Shape.h"
#include "DiscreteAttribute.h"
#include "ContinuousAttribute.h"
#include "../common/RGBA.h"
#include "../common/Vector2.h"
#include "../IDA/types.h"

namespace plasma {
    class TextShape : public Shape {
    public:
        plasma::DiscreteAttribute<std::wstring> string;
        plasma::ContinuousAttribute<FloatRGBA> colors;
        plasma::ContinuousAttribute<FloatRGBA> strokeColors;
        plasma::ContinuousAttribute<FloatRGBA> extrusionColors;
        float size_maybe;
        float some_other_size_maybe;
        _BYTE field_2C0[4];
        float float_2C4;
        std::wstring font_file_name;
        __int64 field_2E8;
        void* scalable_font;
        int int_2F8;
        int field_2FC;
        __int64 field_300;
        FloatVector2 field_308;
        float field_310;
        float field_314;
        float field_318;
        float field_31C;
        float field_320;
        float field_324;
        float field_328;
        float field_32C;
        __int64 field_330;
    };

    static_assert(sizeof(plasma::TextShape) == 0x338, "plasma::TextShape is not the correct size.");
}