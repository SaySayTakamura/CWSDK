#pragma once

#include "cwsdk.h"

namespace modhelper
{
	// This class is using as key ids the ones from dinput.h
	// More info on this github page:
	// https://gist.github.com/dretax/fe37b8baf55bc30e9d63
	class KeybindManager {
	public:
		enum DeviceIds {
			Keyboard = 0,
			Mouse = 1,
		};
		using KeybindValue = std::pair<int, DeviceIds>;
	private:
		std::map<std::string, KeybindValue> keybinds = {};
		std::map<std::string, bool> control_states = {};
		const std::string CONTROL_FILE_PATH = "controls.cfg";
	public:
		KeybindManager() {};

		KeybindValue* GetOrCreateKeybind(std::string name, int default_id, DeviceIds default_device_id) {
			std::ifstream file(CONTROL_FILE_PATH);
			std::string line;
			std::string buttonName;
			int id, device_id;
			bool found = false;

			if (file.is_open()) {
				while (std::getline(file, line)) {
					std::istringstream iss(line);
					iss >> buttonName >> id >> device_id;

					if (buttonName == name) {
						found = true;
						break;
					}
				}
				file.close();

				if (found) {
					this->keybinds.insert_or_assign(name, { id, device_id });
					this->control_states.insert_or_assign(name, false);
					return &this->keybinds.at(name);
				}
				if (CreateKeybindInFile(name, default_id, default_devide_id)) {
					return GetOrCreateKeybind(name, default_id, default_device_id);
				}
				return nullptr;
			}
			else {
				return nullptr;
			}
		}

		bool CreateKeybindInFile(std::string name, int default_id, DeviceIds default_device_id) {
			std::ofstream file;
			file.open(CONTROL_FILE_PATH, std::ios::app); // Ouverture du fichier en mode ajout

			if (file.is_open()) {
				file << name << " " << default_id << " " << default_device_id << "\n"; // Ajout de la ligne et saut de ligne
				file.close(); // Fermeture du fichier
				return true;
			}
			else {
				return false;
			}
		}
	}
}