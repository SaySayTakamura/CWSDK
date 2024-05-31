#pragma once

#include "cwsdk.h"

namespace modhelper
{
	class CraftingManager {
	private:
		std::map<cube::Item*, std::vector<cube::ItemStack>> crafts = {};
	public:
		CraftingManager() {};
		void CreateCraft(cube::Item* item_result, std::vector<cube::ItemStack>* required_items)
		{
			/*std::vector<cube::ItemStack> items = {};
			for (cube::ItemStack stack : *required_items) {
				items.push_back(stack);
			}*/
			this->crafts.insert({ item_result, *required_items });
		}
		std::vector<cube::ItemStack>* GetCraft(cube::Item* item_result)
		{
			for (std::map<cube::Item*, std::vector<cube::ItemStack>>::iterator it = this->crafts.begin(); it != this->crafts.end(); ++it) {
				if (item_result->IsItemEqual(it->first)) {
					return &it->second;
				}
			}
			return nullptr;
		}
	};
}