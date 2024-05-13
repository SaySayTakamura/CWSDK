#include "ItemBuilder.h"

namespace modhelper {
	std::map<std::wstring, modhelper::ModItem*> ItemBuilder::built_items = {};
	std::map<std::pair<cube::Item::CategoryType, int>, modhelper::ModItem*> ItemBuilder::built_items_id = {};
}