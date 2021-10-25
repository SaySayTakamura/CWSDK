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
            virtual void Draw(); //I don't know what controls the position where the widget gets drawn

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

            FloatVector2* GetSize(FloatVector2* vec);
            float GetXSize();
            float GetYSize();
            
            Widget* CreateCopy(Node* node);
            Widget* Copy(Widget* src, Node* node);
        };
}

static_assert(sizeof(plasma::Widget) == 0x1A8, "plasma::Widget is not the correct size.");

#endif // WIDGET_H
