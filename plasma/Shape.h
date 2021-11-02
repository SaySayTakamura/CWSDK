#pragma once

#include "Keyable.h"

namespace plasma {
    class Shape : public Keyable {
    public:
        __int64 field_70;
        __int64 field_78;
        __int64 field_80;
        __int64 field_88;
        __int64 field_90;
    };

    static_assert(sizeof(plasma::Shape) == 0x98, "plasma::Shape is not the correct size.");
}
