#pragma once

#include "Map.h"
#include "Keyable.h"

namespace plasma {
    class Shape : public Keyable {
    public:
        int field_70;
        // 4 bytes padding
        void* field_78;
        plasma::Map<__int32, __int32> map80;
        __int16 field_90;
        // 6 bytes padding
    };

    static_assert(sizeof(plasma::Shape) == 0x98, "plasma::Shape is not the correct size.");
}
