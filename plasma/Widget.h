#ifndef WIDGET_H
#define WIDGET_H

#include "../IDA/types.h"
#include "NamedObject.h"
#include "Map.h"
#include "../common/Matrix4.h"
#include "Matrix.h"
#include "../common/Vector2.h"

class WidgetMatrix {
public:
    float _11, _12, _13, _14;
    float _21, _22, _mintx, _minty;
    float _31, _32, _addtx, _addty;
    float _41, _42, _43, _44;
};

class TransformationMatrix {
public:
    float _sx, _12, _13, _14;
    float _21, _sy, _23, _24;
    float _31, _32, _sz, _34;
    float _tx, _ty, _tz, _44;
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
            plasma::Matrix<float> matrix;
            std::wstring some_string;
            _BYTE gapC0[16];
            plasma::Matrix<float> base_transformation;
            plasma::Matrix<float> local_transformation;
            int some_flag;
            _BYTE gap154[4];
            int field_158;
            char field_15C;
            _BYTE gap160[8];
            __int64 field_168;
            __int64 field_170;
            plasma::Node* node;
            _BYTE gap180[8];
            plasma::Map<int, void*> some_map;
            __int64 field_198;
            char field_1A0;
            //char end;

            FloatVector2* GetSomeVector2(FloatVector2* vec);
            FloatVector2* GetSize(FloatVector2* vec);
            float GetXSize();
            float GetYSize();

            void SetSize(FloatVector2* vec);
            void SetSize(float x, float y);
            
            void Translate(FloatVector2* vec, int flags);
            void Translate(float x, float y, int flags);

            void CW_32B0C0();

            Widget* CreateCopy(Node* node);
            Widget* Copy(Widget* src, Node* node);
        };
}

static_assert(sizeof(plasma::Widget) == 0x1A8, "plasma::Widget is not the correct size.");

#endif // WIDGET_H
