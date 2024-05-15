#pragma once

#include "cwsdk.h"

namespace modhelper {

	//Item data composes a FULL item, this struct is all you need to have an item.
	typedef struct ItemData
	{
		std::wstring itemName;					//Item name
		cube::Item::CategoryType itemCategory;  //Item Category;
		int itemID;								//Item ID
		modhelper::ModItem* itemBehaviour;

		//This is not needed as this struct contain all the needed data;
		//modhelper::ModItem* id_modItem; //Item mod, used to implement the ITEM in the mod;

		ItemData(std::wstring name, modhelper::ModItem* behaviour, cube::Item::CategoryType category, int id)
		{
			this->itemName = name;
			this->itemCategory = category;
			this->itemID = id;
			this->itemBehaviour = behaviour;
		}

		ItemData* SetName(std::wstring name)
		{
			this->itemName = name;
			return this;
		}

		ItemData* SetCategory(cube::Item::CategoryType category)
		{
			this->itemCategory = category;
			return this;
		}

		ItemData* SetBehaviour(modhelper::ModItem* behaviour)
		{
			this->itemBehaviour = behaviour;
			return this;
		}

		ItemData* SetID(int id)
		{
			this->itemID = id;
			return this;
		}
	};
}