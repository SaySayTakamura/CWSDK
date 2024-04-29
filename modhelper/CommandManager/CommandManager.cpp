#include "CommandManager.h"

void modhelper::Commands::CommandsManager::add(fnc command)
{
	fnc c = command;
	command_vector.push_back(c);
}

void modhelper::Commands::CommandsManager::call(std::string name)
{
	for (int i = 0; i < command_vector.size(); i++)
	{
		//Note: this need to be checked, for any duplicated function
		if (command_vector[i].GetName() == name)
		{
			command_vector[i].Call();
		}
	}
}

void modhelper::Commands::CommandsManager::call(int index)
{
	return command_vector[index].Call();
}
