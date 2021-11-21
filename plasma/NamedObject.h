#ifndef NAMEDOBJECT_H
#define NAMEDOBJECT_H

#include "../IDA/types.h"
#include "Object.h"
#include <string>

namespace plasma {
    class NamedObject : public plasma::Object {
        public:
            virtual ~NamedObject();
            std::wstring name;
        };
}
static_assert(sizeof(plasma::NamedObject) == 0x38, "plasma::Widget is not the correct size.");
#endif // NAMEDOBJECT_H
