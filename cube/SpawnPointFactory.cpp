#include "SpawnPointFactory.h"
#include "cwsdk.h"

cube::SpawnPoint* cube::SpawnPointFactory::CreateSpawnPoint()
{
	cube::SpawnPoint* spawnpoint = (cube::SpawnPoint*)new char[sizeof(cube::SpawnPoint)];
	spawnpoint->ctor();
	return spawnpoint;
}

int cube::SpawnPointFactory::GetRaceVariation(int race)
{
	return ((int (*)(int))CWOffset(0x1420F0))(race);
}

void cube::SpawnPointFactory::GenerateSpawnPointAppearance(cube::SpawnPoint* spawnpoint)
{
	((void (*)(int*, cube::Creature::EntityData::Appearance*, void*, bool))CWOffset(0x53E80))(&spawnpoint->race, &spawnpoint->appearance, nullptr, 0);
}

void cube::SpawnPointFactory::GenerateSpawnPointData(cube::SpawnPoint* spawnpoint)
{
	((void (*)(int, int, int, int, int, char*, char*, cube::Equipment*, std::vector<int>*, int*, std::vector<int>*, std::vector<std::vector<cube::ItemStack>>*))CWOffset(0x511E0))(
		spawnpoint->hostility_type, 
		spawnpoint->race, 
		spawnpoint->level, 
		spawnpoint->appearance.flags2, 
		spawnpoint->cult_group, 
		&spawnpoint->classType, 
		&spawnpoint->specialization,
		&spawnpoint->equipment,
		&spawnpoint->vector_8C0,
		&spawnpoint->int_8D8,
		&spawnpoint->vector_8E0,
		&spawnpoint->inventory_tabs);
}
