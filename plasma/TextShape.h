#pragma once

#include "Shape.h"
#include "../common/Vector2.h"

namespace plasma {
    class TextShape : public Shape {
    public:
        __int64 field_98;
        __int64 field_A0;
        __int64 field_A8;
        __int64 field_B0;
        __int64 field_B8;
        __int64 field_C0;
        __int64 field_C8;
        float field_D0;
        float field_D4;
        __int64 field_D8;
        __int64 field_E0;
        __int64 field_E8;
        __int64 field_F0;
        __int64 field_F8;
        __int64 field_100;
        __int64 field_108;
        __int64 field_110;
        __int64 field_118;
        __int64 field_120;
        __int64 field_128;
        __int64 field_130;
        __int64 field_138;
        __int64 field_140;
        __int64 field_148;
        __int64 field_150;
        __int64 field_158;
        __int64 field_160;
        __int64 field_168;
        __int64 field_170;
        __int64 field_178;
        __int64 field_180;
        __int64 field_188;
        __int64 field_190;
        __int64 field_198;
        __int64 field_1A0;
        __int64 field_1A8;
        __int64 field_1B0;
        __int64 field_1B8;
        __int64 field_1C0;
        __int64 field_1C8;
        __int64 field_1D0;
        __int64 field_1D8;
        __int64 field_1E0;
        __int64 field_1E8;
        __int64 field_1F0;
        __int64 field_1F8;
        __int64 field_200;
        __int64 field_208;
        __int64 field_210;
        __int64 field_218;
        __int64 field_220;
        __int64 field_228;
        __int64 field_230;
        __int64 field_238;
        __int64 field_240;
        __int64 field_248;
        __int64 field_250;
        __int64 field_258;
        __int64 field_260;
        __int64 field_268;
        __int64 field_270;
        __int64 field_278;
        __int64 field_280;
        __int64 field_288;
        __int64 field_290;
        __int64 field_298;
        __int64 field_2A0;
        __int64 field_2A8;
        __int64 field_2B0;
        __int64 field_2B8;
        __int64 field_2C0;
        std::wstring font_file_name;
        __int64 field_2E8;
        void* scalable_font;
        __int64 field_2F8;
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