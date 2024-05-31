#pragma once

#include "cwsdk.h"

namespace modhelper
{
	class CraftingManager {
	public:
		enum CraftRequirementType : int {
			None = 0,
			Water = 1,
			Furnace = 3,
			Anvil = 4,
			SpinningWheel = 5,
			Loom = 6,
			Saw = 7,
			Workbench = 8,
			Campfire = 9
		};

		enum CraftItemParameterAccess : int {
			Id,
			Rarity,
			Material,
			Modifier,
			FormulaCategory,
			NumSpirit,
		};

		using CraftingValue = std::pair <modhelper::CraftingManager::CraftRequirementType, std::vector<cube::ItemStack>>;
		using CraftingFilters = std::vector<modhelper::CraftingManager::CraftItemParameterAccess>;

	private:
		using CraftingKey = std::pair <cube::Item*, CraftingFilters>;
		std::map<CraftingKey, CraftingValue> crafts = {};
		CraftingFilters default_parameter_accessors = { Id };

	public:
		CraftingManager() {};

		void CreateCraft(cube::Item* item_result, std::vector<cube::ItemStack>* required_items,
			modhelper::CraftingManager::CraftRequirementType crafting_requirement_type = None,
			CraftingFilters* parameter_access = nullptr)
		{
			if (parameter_access == nullptr) {
				parameter_access = &default_parameter_accessors;
			}
			this->crafts.insert({ {item_result, *parameter_access}, {crafting_requirement_type, *required_items} });
		}

		CraftingValue* GetCraft(cube::Item* item_result)
		{
			for (std::map<CraftingKey, CraftingValue>::iterator it = this->crafts.begin(); it != this->crafts.end(); ++it) {
				if (item_result->category != it->first.first->category) continue;

				bool skip = false;
				for (auto parameter_accessor : it->first.second) {
					if (parameter_accessor == Id) {
						if (item_result->id != it->first.first->id) skip = true;
					}
					if (parameter_accessor == Rarity) {
						if (item_result->rarity != it->first.first->rarity) skip = true;
					}
					if (parameter_accessor == Material) {
						if (item_result->material != it->first.first->material) skip = true;
					}
					if (parameter_accessor == Modifier) {
						if (item_result->modifier != it->first.first->modifier) skip = true;
					}
					if (parameter_accessor == FormulaCategory) {
						if (item_result->formula_category != it->first.first->formula_category) skip = true;
					}
					if (parameter_accessor == NumSpirit) {
						if (item_result->num_spirits != it->first.first->num_spirits) skip = true;
					}
				}

				if (skip) continue;
				return &it->second;
			}
			return nullptr;
		}
	};
}