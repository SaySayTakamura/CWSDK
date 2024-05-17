#pragma once

#include "cwsdk.h"

namespace modhelper {
	class ItemManager
	{
	private:
		std::vector<modhelper::ItemData*> item_vector; //Contains all the items registered.

	public:
		ItemManager() {}

		//Registers the Item to the Manager
		bool Register(ItemData* item)
		{
			if (Exists(item->itemName))
			{
				//Duplicate items are not allowed;
				return false;
			}
			else
			{
				item_vector.push_back(item);
				return true;
			}
			return false;
		}

		bool Exists(std::wstring ItemName)
		{
			for (int i = 0; i < item_vector.size(); i++)
			{
				if (item_vector[i]->itemName == ItemName)
				{
					return true;
				}
			}
			return false;
		}

		bool Exists(cube::Item::CategoryType category, int id)
		{
			for (int i = 0; i < item_vector.size(); i++)
			{
				ItemData* item = item_vector[i];
				if (item->itemCategory == category && item->itemID == id)
				{
					return true;
				}
			}
			return false;
		}

		ItemData* Get(std::wstring name)
		{
			for (int i = 0; i < item_vector.size(); i++)
			{
				if (item_vector[i]->itemName == name)
				{
					return item_vector[i];
				}
			}
			return nullptr;
		}

		ItemData* Get(cube::Item::CategoryType category, int id)
		{
			for (int i = 0; i < item_vector.size(); i++)
			{
				ItemData* item = item_vector[i];
				if (item->itemCategory == category && item->itemID == id)
				{
					return item;
				}
			}
			return nullptr;
		}

	};

	/*class ItemBuilder {
	public:
		static std::map<std::pair<cube::Item::CategoryType, int>, modhelper::ModItem*> built_items_id;
		static std::map<std::wstring, modhelper::ModItem*> built_items;
		std::wstring item_name;
		modhelper::ModItem* modItem;

		ItemBuilder(std::wstring item_name, modhelper::ModItem* item, cube::Item::CategoryType category, int id) {
			this->item_name = item_name;
			item->category = category;
			item->id = id;
			this->modItem = item;
		};

		modhelper::ModItem* build() {
			auto name_search = built_items.find(this->item_name);
			auto id_search = built_items_id.find(std::make_pair(this->modItem->category, this->modItem->id));
			if (name_search != built_items.end() || id_search != built_items_id.end()) {
				return nullptr;
			}
			this->built_items.insert({ this->item_name, this->modItem });
			this->built_items_id.insert({ std::make_pair(this->modItem->category, this->modItem->id), this->modItem });
			return modItem;
		};
	};*/
}