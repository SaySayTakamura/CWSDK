#ifndef WIDGET_H
#define WIDGET_H

#include "../IDA/types.h"
#include "NamedObject.h"
#include "../common/Matrix4.h"
#include "../common/Vector2.h"

class WidgetMatrix {
public:
    float _11, _12, _13, _14;
    float x_end, y_end, _23, _24;
    float x_begin, y_begin, _33, _34;
    float max_width, max_height, min_width, min_height;
};

namespace plasma {
    class Node;
    class Widget : public plasma::NamedObject {
        public:
            virtual void Draw();    // 0x08
            virtual void* F_0x10(void*);    // 0x10
            virtual void* F_0x18(void*);    // 0x18
            virtual bool Return0_0x20();    // 0x20
            virtual bool Return0_0x28();    // 0x28
            virtual void nullsub_1();   // 0x30
            virtual void F_0x38();  // 0x38
            virtual int F_0x40();   // 0x40
            virtual void F_0x48(FloatVector2* vec1, FloatVector2* vec2);    // 0x48
            virtual void nullsub_2();   // 0x50
            virtual void plasma__Widget__cw_32B990();   // 0x58
            virtual void plasma__Widget__cw_32BB40();   // 0x60
            virtual void nullsub_3();   // 0x68
            virtual void nullsub_4();   // 0x70
            virtual void nullsub_5();   // 0x78
            virtual void nullsub_6();   // 0x80
            virtual void nullsub_7();   // 0x88
            virtual void nullsub_8();   // 0x90
            virtual void nullsub_9();   // 0x98
            virtual void nullsub_10();  // 0xA0
            virtual void OnMouseOver(); // 0xA8
            virtual void nullsub_11();  // 0xB0
            virtual void nullsub_12();  // 0xB8
            virtual void nullsub_13();  // 0xC0
            virtual void nullsub_14();  // 0xC8
            virtual void nullsub_15();  // 0xD0
            virtual void nullsub_16();  // 0xD8
            virtual void nullsub_17();  // 0xE0
            virtual void nullsub_18();  // 0xE8
            virtual void nullsub_19();  // 0xF0
            virtual void nullsub_20();  // 0xF8
            virtual void nullsub_21();  // 0x100
            virtual void nullsub_22();  // 0x108
            virtual void nullsub_23();  // 0x110
            virtual void plasma__Widget__cw_32B5A0();   // 0x118
            virtual void plasma__Widget__cw_32B6B0();   // 0x120
            virtual void nullsub_24();  // 0x128
            virtual void nullsub_25();  // 0x130
            virtual void sub_32B6E0();  // 0x138
            virtual void CreateCopy();  // 0x140
            virtual void sub_32A8D0();  // 0x148
            virtual void nullsub_26();  // 0x150

            void* deformer_vtable;
            float scale;
            FloatVector2 some_size;
            float scale2;
            _BYTE gap44[8];
            __int64 d3d11_render_surface_ptr;
            WidgetMatrix matrix;
            __int64 field_A0;
            _BYTE gapA8[208];
            plasma::Node* node;
            _BYTE gap180[39];
            char end;

            FloatVector2* GetSomeVector2(FloatVector2* vec);
            FloatVector2* GetSize(FloatVector2* vec);
            float GetXSize();
            float GetYSize();
            
            void Translate(FloatVector2* vec, int flags);
            void Translate(float x, float y, int flags);

            Widget* CreateCopy(Node* node);
            Widget* Copy(Widget* src, Node* node);
        };
}

static_assert(sizeof(plasma::Widget) == 0x1A8, "plasma::Widget is not the correct size.");

#endif // WIDGET_H
