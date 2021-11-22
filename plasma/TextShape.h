#pragma once

#include "Shape.h"
#include "DiscreteAttribute.h"
#include "ContinuousAttribute.h"
#include "../common/RGBA.h"
#include "../common/Vector2.h"
#include "../IDA/types.h"

namespace plasma {
    enum TextPivot : int {
        Left = 0,
        Center,
        Right
    };

    class TextShape : public Shape {
    public:
        virtual ~TextShape();
        // Loads the scalable font by the stored file name.
        // Flag: Override font if already defined
        virtual void Load(bool flag);
        virtual void Draw(plasma::Node* node);
        virtual bool IsPointInsideShape(FloatVector2* vec);
        virtual FloatVector2* GetSomeMaxVector(FloatVector2* vec);
        virtual FloatVector2* GetSomeMinVector(FloatVector2* vec);
        virtual TextShape* CreateCopy();


        plasma::DiscreteAttribute<std::wstring> string;
        plasma::ContinuousAttribute<FloatRGBA> colors;
        plasma::ContinuousAttribute<FloatRGBA> strokeColors;
        plasma::ContinuousAttribute<FloatRGBA> extrusionColors;
        float text_size;
        float stroke_size;
        float horizontal_spacing;
        float vertical_spacing;
        std::wstring font_file_name;
        __int64 field_2E8;
        void* scalable_font;
        int text_pivot;
        int field_2FC;
        FloatVector2 some_max;
        FloatVector2 some_min;
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