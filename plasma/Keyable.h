#ifndef KEYABLE_H
#define KEYABLE_H

#include "../IDA/types.h"
#include "NamedObject.h"
#include <list>

namespace plasma {
    class Keyable : public plasma::NamedObject {
        public:
            virtual ~Keyable();
            virtual void Load(bool flag); //0x8
            // Unknown list type
            std::list<void*> list_38;
            __int16 field_48;
            // 6 bytes padding
            std::wstring string;
        };

    static_assert(sizeof(plasma::Keyable) == 0x70, "plasma::Keyable is not the correct size.");
}

#endif // KEYABLE_H
