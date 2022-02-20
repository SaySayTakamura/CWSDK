#pragma once

#include "SpawnPoint.h"

namespace cube
{
	class SpawnPointFactory
	{
	public:
		// Creates and initializes a spawnpoint
		static cube::SpawnPoint* CreateSpawnPoint();

		// Gets all variations of a given race
		static int GetRaceVariation(int race);

		// Generates and adds the cube::Appearance based on the race variable of the spawnpoint
		static void GenerateSpawnPointAppearance(cube::SpawnPoint* spawnpoint);

		// Generates and adds items, abilities e.t.c. based on:
		// hostility_type, race, level, appearance_flags and cult_group
		static void GenerateSpawnPointData(cube::SpawnPoint* spawnpoint);
	};
}