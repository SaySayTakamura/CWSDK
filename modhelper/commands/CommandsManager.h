#pragma once
#include <map>
#include <string>
#include "modhelper/commands/BaseCommand.h"
#include "modhelper/commands/HelpCommand.h"

class CommandsManager {
public:
	CommandsManager();
	void registerCommand(BaseCommand* command);
	void registerCommand(const wchar_t* call_name, void* command_func);
	void setModId(const wchar_t* mod_id);
	const wchar_t* getModId();

	BaseCommand* getCommand(std::wstring* call_name);
private:
	const wchar_t* mod_id; // will need to replace this to a more global variable later.
	std::map<const wchar_t*, BaseCommand*> commands_map;
};