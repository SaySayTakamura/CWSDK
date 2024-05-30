#pragma once

#include "cwsdk.h"

namespace modhelper
{
	class CraftingManager {
	private:
		std::map<cube::Item, std::vector<cube::ItemStack>> crafts;
	public:
		CraftingManager() {};
		void CreateCraft(cube::Item* item_result, std::vector<cube::ItemStack>* required_items);
		std::vector<cube::ItemStack>* GetCraft(cube::Item* item);
	};
};