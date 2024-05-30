#include "CraftingManager.h"

void modhelper::CraftingManager::CreateCraft(cube::Item* item_result, std::vector<cube::ItemStack>* required_items)
{
	cube::Item item;
	item.Copy(item_result);
	std::vector<cube::ItemStack> items = {};
	for (cube::ItemStack stack : *required_items) {
		items.push_back(stack);
	}
	this->crafts.insert({ item, items });
}

std::vector<cube::ItemStack>* modhelper::CraftingManager::GetCraft(cube::Item* item_result)
{
	cube::Item item;
	item.Copy(item_result);
	auto search = this->crafts.find(item);
	if (search != this->crafts.end())
		return &search->second;
	return nullptr;
}
