#pragma once

#include "cwsdk.h"

namespace modhelper
{
	class CraftingManager {
	private:
		std::map<cube::Item*, std::vector<cube::ItemStack>> crafts;
	public:
		CraftingManager() {};
		void CreateCraft(cube::Item* item_result, std::vector<cube::ItemStack>* required_items)
		{
			cube::Item* item;
			item->Copy(item_result);
			std::vector<cube::ItemStack> items = {};
			for (cube::ItemStack stack : *required_items) {
				items.push_back(stack);
			}
			this->crafts.insert({ item, items });
		}
		std::vector<cube::ItemStack>* GetCraft(cube::Item* item_result)
		{
			cube::Item* item;
			item->Copy(item_result);
			auto search = this->crafts.find(item);
			if (search != this->crafts.end())
				return &search->second;
			return nullptr;
		}
	};
}