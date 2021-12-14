#include "Equipment.h"
#include "../cwsdk.h"

cube::Equipment* cube::Equipment::Copy(cube::Equipment* other)
{
	return ((cube::Equipment* (*)(cube::Equipment*, cube::Equipment*))CWOffset(0x3B6B0))(this, other);
}