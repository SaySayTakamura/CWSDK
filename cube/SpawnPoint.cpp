#include "SpawnPoint.h"
#include "SpawnPoint.h"
#include "SpawnPoint.h"
#include "SpawnPoint.h"
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

void cube::SpawnPoint::Generate()
{
	this->SetSpawnPointAppearance(&this->race, &this->appearance, nullptr, 0);
	this->SetSpawnPointData(
		this->hostility_type,
		this->race,
		this->level,
		this->appearance.flags2,
		this->cult_group,
		(_BYTE*)&this->classType,
		(_BYTE*)&this->specialization,
		&this->equipment,
		(std::vector<int>*) & this->field_8C0,
		&this->int_8D8,
		(std::vector<int>*) & this->field_8E0,
		(std::vector<std::vector<cube::ItemStack>>*) & this->field_7F0);
}

void cube::SpawnPoint::SetSpawnPointAppearance(int* race, cube::Creature::EntityData::Appearance* appearance, void* a3, bool a4)
{
	((void (*)(int*, cube::Creature::EntityData::Appearance*, void*, bool))CWOffset(0x53E80))(race, appearance, a3, a4);
}

void cube::SpawnPoint::SetSpawnPointData(int hostility_type, int race, int level, int appearance_flags, int cult_group, _BYTE* classType, _BYTE* specialization, cube::Equipment* equipment, std::vector<int>* abilities_maybe, int* a10, std::vector<int>* other_abilities_maybe, std::vector<std::vector<cube::ItemStack>>* inventory_tabs)
{
	((void (*)(int, int, int, int, int, _BYTE*, _BYTE*, cube::Equipment*, std::vector<int>*, int*, std::vector<int>*, std::vector<std::vector<cube::ItemStack>>*))CWOffset(0x511E0))(hostility_type, race, level, appearance_flags, cult_group, classType, specialization, equipment, abilities_maybe, a10, other_abilities_maybe, inventory_tabs);
}
