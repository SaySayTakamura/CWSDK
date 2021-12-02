#ifndef D3D11ENGINE_H
#define D3D11ENGINE_H

#include "../IDA/types.h"
#include "Engine.h"
#include "TextShape.h"
#include "common/BytesIO.h"

namespace plasma {
    class D3D11Engine : public plasma::Engine {
        public:
            char field_290[840];

            void MiddleMouseButtonUp();
            void LeftMouseButtonUp();
            void RightMouseButtonUp();

            plasma::Node* CreateNode(plasma::Transformation* transformation, plasma::TextShape* text_shape, plasma::Display* display, plasma::Node* root_node, std::wstring* name);
            plasma::Node* CreateNode(plasma::Node* root_node, std::wstring* name);

            plasma::TextShape* CreateTextShape(std::wstring* str, std::wstring* name);
            plasma::TextShape* CreateTextShape();

            bool LoadNodeFromFile(std::wstring* filename, plasma::Node* node, int a4, int a5);
            bool LoadNodeFromFile(std::wstring* filename, plasma::Node* node, int a4, int a5, void* keyObj);

            void* cw_33BCF0(void* a2, plasma::Object* object);
            void* cw_33BFE0(void* a2, plasma::Widget* widget);
        };
}

#endif // D3D11ENGINE_H
