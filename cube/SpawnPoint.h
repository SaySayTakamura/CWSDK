#pragma once

#include "../common/Vector3.h"
#include "../common/types.h"
#include <map>

#include "Creature.h"

namespace cube
{
	class SpawnPoint
	{
	public:
		LongVector3 position;
		float yaw; // Where it is looking
		int hostility_type; // EntityBehaviour
		int race;
		int level;
		int cult_group; // [1 - 22] (0 = nothing)
		int int_2C;
		int int_30;
		__int8 classType;
		__int8 specialization;
		long long creature_id;
		__int64 field_40; // Linked creature id
		int int_48;
		int some_state;
		cube::Creature::EntityData::Appearance appearance;
		__int8 byte_100;
		__int8 byte_101;
		_BYTE gap_102[14];
		cube::Equipment equipment;
		std::vector<std::vector<cube::ItemStack>> inventory_tabs;
		__int64 field_808;
		cube::Item item;
		int gold;
		int field_8B0;
		//__int64 field_8AC; // No pointer, because it is not 8 offset
		// 4 bytes padding
		int field_8B8;
		int current_ability;
		std::vector<int> vector_8C0; // Maybe a vector of abilities
		int int_8D8;
		// 4 bytes padding
		std::vector<int> vector_8E0; // Maybe a vector of abilities
		IntVector2 zone_position;
		std::map<void*, void*> map_900;
		std::map<void*, void*> map_910;
		int int_920;
		// 4 bytes padding
		std::map<void*, void*> map_928;
		std::list<void*> list_938;
		int int_948;
		// 4 bytes padding

		cube::SpawnPoint* ctor();

		/*
		* BossType ids:
		* 1-3: Basic NPC types, generated based on position and id
		* 7: Sorcerer / Wizard (depending on position)
		* 22: Witch
		* Anything else: random race returned
		* TODO: Move to factory
		*/
		void SetMageTowerBossRace(int zone_x, int zone_y, int bossType);
	};
}

static_assert(sizeof(cube::SpawnPoint) == 0x950, "cube::SpawnPoint is not the correct size.");