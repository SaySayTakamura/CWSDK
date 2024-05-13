#pragma once

#include "cwsdk.h"

namespace modhelper {

	class ItemBuilder {
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
	};
}