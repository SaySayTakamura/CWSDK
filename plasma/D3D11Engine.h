#ifndef D3D11ENGINE_H
#define D3D11ENGINE_H

#include "../IDA/types.h"
#include "Engine.h"

namespace plasma {
    class D3D11Engine : public plasma::Engine {
        public:
            char field_290[840];

            void MiddleMouseButtonUp();
            void LeftMouseButtonUp();
            void RightMouseButtonUp();
        };
}

#endif // D3D11ENGINE_H
