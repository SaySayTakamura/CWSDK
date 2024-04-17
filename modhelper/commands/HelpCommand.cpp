#include "HelpCommand.h"

int HelpCommand::RunCommand() {
	auto game = cube::GetGame();
	game->PrintMessage(L"This is the help message");
	return 1;
}