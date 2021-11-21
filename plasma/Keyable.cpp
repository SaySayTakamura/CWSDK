#include "Keyable.h"
#include "../cwsdk.h"

plasma::Keyable::~Keyable()
{
	((void (*)(plasma::Keyable*))CWOffset(0x368F00))(this);
}

void plasma::Keyable::Load(bool flag) {}
