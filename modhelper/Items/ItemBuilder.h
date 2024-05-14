#pragma once

#include "cwsdk.h"

namespace modhelper {



	//Item data composes a FULL item, this struct is all you need to have an item.
	typedef struct ItemData
	{
		std::string itemName; //Item name
		std::string spriteName; //itemSpriteName

		cube::Item::CategoryType itemCategory; //Item Category;
		modhelper::ModItem* itemBehaviour;

		int itemID; //Item ID



		//This is not needed as this struct contain all the needed data;
		//modhelper::ModItem* id_modItem; //Item mod, used to implement the ITEM in the mod;

		ItemData(std::string name, modhelper::ModItem* behaviour, cube::Item::CategoryType cat, int id)
		{
			this->itemName = name;
			this->itemBehaviour = behaviour;
			this->itemID = id;
			this->itemCategory = cat;
		}

		ItemData()
		{
			this->itemName = "UNDEFINED";
			this->itemBehaviour = nullptr;
			this->itemID = -1;
			this->itemCategory = cube::Item::CategoryType::Amulet;
		}


		void SetName(std::string name)
		{
			this->itemName = name;
		}
		void SetCategory(cube::Item::CategoryType cat)
		{
			this->itemCategory = cat;
		}
		void SetBehaviour(modhelper::ModItem* behaviour)
		{
			this->itemBehaviour = behaviour;
		}
		void SetID(int id)
		{
			this->itemID = id;
		}

	};
	class ItemManager
	{
	private:
		std::vector<ItemData*> item_vector; //Contains all the items registered.

	public:
		ItemManager() {}

		//Registers the Item to the Manager
		bool Register(ItemData item)
		{
			if (Exists(item.itemName) == true)
			{
				//Duplicate items are not allowed;
				return false;
			}
			else
			{
				item_vector.push_back(&item);
			}
		}

		bool Exists(std::string ItemName)
		{
			for (int i = 0; i < item_vector.size(); i++)
			{
				if (item_vector[i]->itemName == ItemName) 
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		bool Exists(int id)
		{
			for (int i = 0; i < item_vector.size(); i++)
			{
				if (item_vector[i]->itemID == id)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}

		ItemData* Get(std::string name)
		{

			for (int i = 0; i < item_vector.size(); i++)
			{
				int index = i;
				if (item_vector[index]->itemName == name)
				{
					return item_vector[index];
				}
				else
				{
					return nullptr;
				}
				index = -1;
			}
			
		}
		ItemData* Get(int id)
		{

			for (int i = 0; i < item_vector.size(); i++)
			{
				int index = i;
				if (item_vector[index]->itemID == id)
				{
					return item_vector[index];
				}
				else
				{
					return nullptr;
				}
				index = -1;
			}

		}
	};

	//Temporary name, change it as you please.
	static ItemManager GLOBAL_ITEM_MANAGER;

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