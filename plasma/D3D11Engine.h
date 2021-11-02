#ifndef D3D11ENGINE_H
#define D3D11ENGINE_H

#include "../IDA/types.h"
#include "Engine.h"
#include "TextShape.h"

namespace plasma {
    class D3D11Engine : public plasma::Engine {
        public:
            char field_290[840];

            void MiddleMouseButtonUp();
            void LeftMouseButtonUp();
            void RightMouseButtonUp();

            plasma::Node* CreateNode(plasma::Transformation* transformation, plasma::TextShape* text_shape, plasma::Display* display, plasma::Node* root_node, std::wstring* name);
            plasma::Node* CreateNode(plasma::Node* root_node, std::wstring* name);

            bool LoadNodeFromFile(std::wstring* filename, plasma::Node* node, int a4, int a5, void* some_struct);
        };
}

#endif // D3D11ENGINE_H
