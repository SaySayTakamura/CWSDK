#pragma once

#include "cwsdk.h"

namespace modhelper {
	class SpriteLoader {
	private:
		static std::map < std::string, cube::Sprite*> loaded_sprites;
	public:
		static cube::Sprite* LoadModel(modhelper::ModMD::ModMetadata* mod_md, cube::SpriteManager* sprite_manager, std::wstring model_name, std::string file_path) {
			if (IsSpriteLoaded(file_path)) {
				return nullptr;
			}

			std::string path = GetSpriteFilePath(mod_md, file_path);
			cube::Sprite* sprite = sprite_manager->CreateSprite();
			std::string model_id = std::to_string(sprite_manager->sprites.size());
			sprite_manager->ParseCubToSprite(sprite, path);
			sprite_manager->sprites.push_back(sprite);
			loaded_sprites.insert({ file_path, sprite });
			return sprite;
		}

		static bool IsSpriteLoaded(modhelper::ModMD::ModMetadata* mod_md, std::string file_path) {
			auto seach = loaded_sprites.find(file_path);
			if (search != loaded_sprites.end()) {
				return true;
			}
			return false;
		}

		static std::string GetSpriteFilePath(modhelper::ModMD::ModMetadata* mod_md, std::string file_path) {
			return "mods/" + mod_md->GetName() + "/sprites/" + file_path; // path: mods/mod_id/sprites/file_path.cub
		}
	}
}