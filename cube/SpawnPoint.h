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
		float float_18;
		int int_1C;
		int int_20;
		int int_24;
		int int_28;
		int int_2C;
		int int_30;
		__int8 byte_34;
		__int8 byte_35;
		long long long_38;
		__int64 field_40;
		int int_48;
		int int_4C;
		cube::Creature::EntityData::Appearance appearance;
		__int8 byte_100;
		__int8 byte_101;
		_BYTE gap_102[14];
		cube::Equipment equipment;
		__int64 field_7F0; // Maybe std::vector<std::vector<cube::ItemStack>>
		__int64 field_7F8; // Which is the inventory
		__int64 field_800;
		__int64 field_808;
		cube::Item item;
		__int64 field_8AC; // No pointer, because it is not 8 offset
		// 4 bytes padding
		__int64 field_8B8;
		__int64 field_8C0; // Maybe std::vector<int>
		__int64 field_8C8; // Which is maybe a vector of abilities
		__int64 field_8D0;
		int int_8D8;
		// 4 bytes padding
		__int64 field_8E0; // Maybe std::vector<int>
		__int64 field_8E8; // Which is maybe a vector of abilities
		__int64 field_8F0;
		IntVector2 intVector_8F8;
		std::map<void*, void*> map_900;
		std::map<void*, void*> map_910;
		int int_920;
		// 4 bytes padding
		std::map<void*, void*> map_928;
		std::list<void*> list_938;
		int int_948;
		// 4 bytes padding
	};
}

static_assert(sizeof(cube::SpawnPoint) == 0x950, "cube::SpawnPoint is not the correct size.");