#include "NamedObject.h"
#include "../cwsdk.h"

plasma::NamedObject::~NamedObject()
{
	((void (*)(plasma::NamedObject*))CWOffset(0x329730))(this);
}
