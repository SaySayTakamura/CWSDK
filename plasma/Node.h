#ifndef NODE_H
#define NODE_H

#include "../IDA/types.h"
#include "../common/Matrix4.h"
#include "../common/types.h"
#include "NamedObject.h"
#include "Vector.h"
#include <list>

namespace plasma {
    class Transformation;
    class Display;
    class Widget;
    class Node : public plasma::NamedObject {
        public:
            __int64 field_38;
            plasma::Node* parent;
            std::list<plasma::Node*> nodes;
            __int64 field_58;
            plasma::Transformation* transformation;
            plasma::Display* display;
            plasma::Widget* widget1;
            plasma::Widget* widget2;
            int some_flags;
            char some_bool;
            // 3 bytes padding
            void* engine_vtable;
            __int64 field_90;
            __int64 field_98;
            __int64 field_A0;
            __int64 field_A8;
            __int64 field_B0;
            __int64 field_B8;
            __int64 field_C0;

            void Translate(plasma::Vector<2, float>* base, plasma::Vector<2, float>* offset);
            void Translate(float baseX, float baseY, float offsetX, float offsetY);

            i32 Draw(u32 flags);

            void MaybeLoadTransformationMatrix(Matrix4* matrix);

            plasma::Node* FindChildNodeByName(std::wstring* name);
            plasma::Node* CopyMaybe(plasma::Node* node);

            void SetTransformation(plasma::Transformation* transformation);
            void SetDisplay(plasma::Display* display);
        };
}
static_assert(sizeof(plasma::Node) == 0xC8, "plasma::Node is not the correct size.");
#endif // NODE_H
