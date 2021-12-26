#include "SpawnPoint.h"
#include "cwsdk.h"

cube::SpawnPoint* cube::SpawnPoint::ctor()
{
	return ((cube::SpawnPoint* (*)(cube::SpawnPoint*))CWOffset(0x118A60))(this);
}
