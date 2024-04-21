#pragma once

#include "../IDA/types.h"
#include "../common/Matrix4.h"
#include "../common/types.h"
#include "../common/Vector2.h"
#include "NamedObject.h"
#include "Vector.h"
#include "TextShape.h"
#include <list>

namespace plasma {
    class Transformation;
    class Display;
    class Widget;
    class Node : public plasma::NamedObject {
        public:
            __int64 field_38;
            plasma::Node* parent;
            std::list<plasma::Node*> children;
            plasma::TextShape* text_shape;
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

            // Only called once in GUI init, but here for documentation purposes
            plasma::Node* ctor(plasma::D3D11Engine* engine, plasma::Transformation* transformation, std::list<plasma::Node*>* nodes, plasma::Display* display, std::wstring* name);


            void SetTransformation(plasma::Transformation* transformation);
            void SetDisplay(plasma::Display* display);

            void Translate(FloatVector2* base, FloatVector2* offset);
            void Translate(float baseX, float baseY, float offsetX, float offsetY);
            void Translate(float x, float y);

            plasma::Node* Draw(u32 flags);

            bool IsVisible();
            void SetVisibility(bool visible);

            // Might just be the full implementation of IsMouseOverNode
            plasma::Node* GetHoveredNode(FloatVector2* mouse_pos, u32 flags);
            bool IsMouseOverNode();

            void LoadSomeMatrix(Matrix4* matrix);

            plasma::Node* FindChildByName(const std::wstring* name);

            void FindByNameAndSetString(std::wstring* name, std::string* str, int flags);
            void FindByNameAndSetString(std::wstring* name, std::wstring* str, int flags);

            plasma::Node* CreateCopy(plasma::Node* parent);
            plasma::Node* CreateDeepCopy(plasma::Node* parent);
            void ClearChildrenMaybe();

            void SetText(std::wstring* text);

            void SetParent(plasma::Node* node);
            void AddChild(plasma::Node* node);

            void CW_334330(plasma::Node* node);
            void CW_334410(plasma::Widget* widget);
            void CW_335830();
            void CW_3356D0();

            void SetCallback(int event_type, void(*function)(uint64_t), char a1, char a2);

            static plasma::Node* CreateButton(plasma::Node* root_node, std::wstring* name, int button_type, std::wstring* text, IntVector2* pos, IntVector2* off);
    };
}
static_assert(sizeof(plasma::Node) == 0xC8, "plasma::Node is not the correct size.");
