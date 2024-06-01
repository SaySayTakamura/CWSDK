#pragma once

#include "cwsdk.h"

#include <fstream>
#include <sstream>

namespace modhelper
{
	// This class is using as key ids the ones from win32
	// More info on this microsoft page:
	// https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	class KeybindManager {
	public:
		enum DeviceIds : int {
			Keyboard = 0,
			Mouse = 1,
		};
		using KeybindValue = std::pair<int, DeviceIds>;
		std::map<std::string, bool> control_states = {};
		std::map<std::string, bool> old_control_states = {};
	private:
		std::map<std::string, KeybindValue> keybinds = {};
		const std::string CONTROL_FILE_PATH = "controls.cfg";
	public:
		KeybindManager() {};

		std::string GetKeybindName(modhelper::ModMetadata* metadata, std::string o_name) {
			return metadata->GetName() + std::string("::") + o_name;
		}

		KeybindValue* GetOrCreateKeybind(modhelper::ModMetadata* metadata, std::string o_name, int default_id, DeviceIds default_device_id) {
			std::ifstream file(CONTROL_FILE_PATH);
			std::string line;
			std::string buttonName;
			int id, device_id;
			bool found = false;
			std::string name = GetKeybindName(metadata, o_name);

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
					this->keybinds.insert_or_assign(name, std::make_pair(id, (DeviceIds)device_id));
					this->control_states.insert_or_assign(name, false);
					this->old_control_states.insert_or_assign(name, false);
					return &this->keybinds.at(name);
				}
				if (CreateKeybindInFile(name, default_id, default_device_id)) {
					return GetOrCreateKeybind(metadata, o_name, default_id, default_device_id);
				}
				return nullptr;
			}
			else {
				return nullptr;
			}
		}

		bool CreateKeybindInFile(std::string name, int default_id, DeviceIds default_device_id) {
			std::ofstream file;
			file.open(CONTROL_FILE_PATH, std::ios::app);

			if (file.is_open()) {
				file << name << " " << default_id << " " << default_device_id << "\n";
				file.close();
				return true;
			}
			return false;
		}

		std::map<std::string, KeybindValue>* GetKeybinds() {
			return &this->keybinds;
		}

		bool isKeyPressed(modhelper::ModMetadata* metadata, std::string o_name) {
			std::string name = GetKeybindName(metadata, o_name);
			bool now = control_states.at(name);
			return now;
		}

		bool isKeyJustPressed(modhelper::ModMetadata* metadata, std::string o_name) {
			std::string name = GetKeybindName(metadata, o_name);
			bool now = control_states.at(name);
			bool old = old_control_states.at(name);
			if (now && !old) return true;
			return false;
		}

		bool isKeyJustReleased(modhelper::ModMetadata* metadata, std::string o_name) {
			std::string name = GetKeybindName(metadata, o_name);
			bool now = control_states.at(name);
			bool old = old_control_states.at(name);
			if (!now && old) return true;
			return false;
		}
	};
}