#include "BaseCommand.h"

BaseCommand::BaseCommand(const wchar_t* call_name)
{
	this->call_name = call_name;
}

void BaseCommand::setFunction(void* func_call)
{
	this->func_call = func_call;
}

int BaseCommand::RunCommand()
{
	auto game = cube::GetGame();
	game->PrintMessage(L"TODO: this function isn't implemented yet! (override me)");
	return 1;
}
