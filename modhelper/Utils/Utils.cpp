#include "Utils.h"

void modhelper::Utils::Print(std::string format, ...)
{
	char msg[MAX_MESSAGE_LENGTH];
	va_list ap;
	va_start(ap, format);
	vsnprintf(msg, sizeof(char) * MAX_MESSAGE_LENGTH, format.c_str(), ap);
	va_end(ap);

	//printf("%s\n", msg);

	auto wmsg = std::wstring((wchar_t*)msg);

	if (HasGameLoaded() == true)
	{
		auto g = cube::GetGame();
		g->PrintMessage(wmsg.c_str());
	}
	else
	{
		ShowMessage("-GAME IS NOT LOADED AT THIS MOMENT-");
	}

}

void modhelper::Utils::ShowMessage(std::string fmt_message, ...)
{
	char msg[MAX_MESSAGE_LENGTH];
	va_list ap;
	va_start(ap, fmt_message);
	vsnprintf(msg, sizeof(char) * MAX_MESSAGE_LENGTH, fmt_message.c_str(), ap);
	va_end(ap);

	MessageBoxA(0, msg, "MESSAGE", MB_OK | MB_ICONINFORMATION);
}

bool modhelper::Utils::ShowPrompt(std::string fmt_message, ...)
{
	char msg[MAX_MESSAGE_LENGTH];
	va_list ap;
	va_start(ap, fmt_message);
	vsnprintf(msg, sizeof(char) * MAX_MESSAGE_LENGTH, fmt_message.c_str(), ap);
	va_end(ap);

	int prompt_r = MessageBoxA(0, msg, "PROMPT", MB_YESNO | MB_ICONQUESTION);

	switch (prompt_r)
	{
	case IDYES:
		return true;
		break;
	case IDNO:
		return false;
		break;
	}

	return false;
}
