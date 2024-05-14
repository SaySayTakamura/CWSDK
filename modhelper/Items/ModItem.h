#pragma once

#include "cwsdk.h"

namespace modhelper {
	class ModItem {
	public:

		//Constructor
		ModItem();

		//Used when we create the item (like doing the initialize function the mods)
		virtual void OnCreate() {}

		//Whenever the PLAYER uses this item, this function is called
		virtual void OnUse() {}

		//Whenever we Spawn this item into the world this function is called
		virtual void OnSpawn(){}

		//Whenever this item becomes a loot and its collected by the player this function is called.
		virtual void OnLoot() {}

		//Whenver the item is despawned this function is called.
		virtual void OnDestroy() {}

		virtual cube::Sprite* GetModel(cube::SpriteManager*, cube::Item* item) { return nullptr; }
	};
}