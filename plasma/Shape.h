#pragma once

#include "Map.h"
#include "Keyable.h"
#include "../common/Vector2.h"
#include "../common/Matrix4.h"

namespace plasma {
    class Shape : public Keyable {
    public:
        virtual ~Shape();
        virtual void Load(bool flag);
        virtual void Draw(plasma::Node* node);
        virtual bool v_0x18(FloatVector2* vec, void* unk_type, Matrix4* m1, Matrix4* m2);
        virtual bool IsPointInsideShape(FloatVector2* vec);
        virtual bool v_0x28();
        virtual FloatVector2* GetSomeMaxVector(FloatVector2* vec);
        virtual FloatVector2* GetSomeMinVector(FloatVector2* vec);
        virtual bool v_0x40();
        virtual bool v_0x48();
        virtual void v_0x50();
        virtual void v_0x58();
        virtual void v_0x60();
        virtual Shape* CreateCopy();
        virtual void SomeFontFunction(void* unk_type);
        virtual void v_0x78();
        virtual void v_0x80();
        virtual bool v_0x88();
        virtual void v_0x90();
        int field_70;
        // 4 bytes padding
        void* field_78;
        plasma::Map<__int32, __int32> map80;
        __int16 field_90;
        // 6 bytes padding
    };

    static_assert(sizeof(plasma::Shape) == 0x98, "plasma::Shape is not the correct size.");
}
