#include "CommandsManager.h"

CommandsManager::CommandsManager()
{
	HelpCommand help(L"help");
	registerCommand(&help);
}

//template <typename Func, typename... Args>
//void test3(Func&& func, Args&&... args)
//{
//	std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
//}

void CommandsManager::registerCommand(BaseCommand* command)
{
	commands_map.insert({ command->call_name, command });
}

void CommandsManager::registerCommand(const wchar_t* call_name, void* command_func)
{
	BaseCommand command(call_name);
	command.setFunction(command_func);
	commands_map.insert({ call_name, &command });
}

void CommandsManager::setModId(const wchar_t* mod_id)
{
	if (this->mod_id.size() > 0) return // avoid being replaced
	this->mod_id = mod_id;
}

const wchar_t* CommandsManager::getModId()
{
	return this->mod_id
}

BaseCommand* CommandsManager::getCommand(std::wstring* call_name)
{
	auto search = commands_map.find(call_name->c_str());
	if (search != commands_map.end())
		return search->second;
	return nullptr;
}
