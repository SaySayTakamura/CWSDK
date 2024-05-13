#pragma once

#include "cwsdk.h"

namespace modhelper {
	class ModItem {
	public:
        cube::Item::CategoryType category;
		int id;

		ModItem() {};

		virtual cube::Sprite* getModel(cube::SpriteManager* sprite_manager, cube::Item* item) { return nullptr; };
        //void getItem(cube::Item* item);
	};
}