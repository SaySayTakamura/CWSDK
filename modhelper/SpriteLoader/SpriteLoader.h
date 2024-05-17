#pragma once

#include "cwsdk.h"

namespace modhelper {
	class SpriteLoader {
	private:
		std::map<std::wstring, cube::Sprite*> loaded_sprites;
	public:
		SpriteLoader() {}

		cube::Sprite* LoadModel(modhelper::ModMetadata* mod_md, cube::SpriteManager* sprite_manager, std::wstring model_name, std::string file_path) {
			if (IsSpriteLoaded(model_name)) {
				return nullptr;
			}

			std::string path = GetSpriteFilePath(mod_md, file_path);
			cube::Sprite* sprite = sprite_manager->CreateSprite();
			std::string model_id = std::to_string(sprite_manager->sprites.size());
			sprite_manager->ParseCubToSprite(sprite, path);
			sprite_manager->sprites.push_back(sprite);
			loaded_sprites.insert({ model_name, sprite });
			return sprite;
		}

		bool IsSpriteLoaded(std::wstring model_name) {
			auto search = loaded_sprites.find(model_name);
			if (search != loaded_sprites.end()) {
				return true;
			}
			return false;
		}

		std::string GetSpriteFilePath(modhelper::ModMetadata* mod_md, std::string file_path) {
			return std::string("Mods/") + std::string(mod_md->GetName()) + std::string("/sprites/") + file_path;  // path: mods/mod_id/sprites/file_path.cub
		}

		cube::Sprite* GetSprite(std::wstring model_name) {
			if (!IsSpriteLoaded(model_name)) return nullptr;
			auto search = loaded_sprites.find(model_name);
			return search->second;
		}
	};
}