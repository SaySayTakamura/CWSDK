#include "SpawnPoint.h"
#include "cwsdk.h"

cube::SpawnPoint* cube::SpawnPoint::ctor()
{
	return ((cube::SpawnPoint* (*)(cube::SpawnPoint*))CWOffset(0x118A60))(this);
}

void cube::SpawnPoint::SetMageTowerBossRace(int zone_x, int zone_y, int bossType)
{
	((void (*)(cube::SpawnPoint*, int, int, int))CWOffset(0x12A420))(this, zone_x, zone_y, bossType);
}
