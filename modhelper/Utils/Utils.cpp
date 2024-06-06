#include "Utils.h"
#include <codecvt>

//Currently Broken, message it's not being parsed correctly.
//Extremly Broken, fix this ASAP.
//To: Future Edgar.
//From: Edgar
//Fixed in 03/06/2024
//Remove comment on release
void modhelper::Utils::Print(std::string format, ...)
{
	char msg[MAX_MESSAGE_LENGTH];
	va_list ap;
	va_start(ap, format);
	vsnprintf(msg, sizeof(char) * MAX_MESSAGE_LENGTH, format.c_str(), ap);
	va_end(ap);

	//Code taken from StackOverflow - Issue #18244133
	//Link: https://stackoverflow.com/questions/18244133/how-do-i-convert-a-string-to-a-wstring-using-the-value-of-the-string
	
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wmsg = converter.from_bytes(msg);

	//Note that this might cause issues.
	//When calling this from Initialize() the game will crash withou ever showing any error.
	auto g = cube::GetGame();
	g->PrintMessage(wmsg.c_str());

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

std::wstring modhelper::Utils::String_2_WString(std::string str)
{
	//setup converter
	using convert_type = std::codecvt_utf8_utf16<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
	std::wstring converted_string = converter.from_bytes(str);

	return converted_string;
}

std::string modhelper::Utils::WString_2_String(std::wstring wstr)
{
	//setup converter
	using convert_type = std::codecvt_utf8_utf16<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
	std::string converted_string = converter.to_bytes(wstr);

	return converted_string;
}

bool modhelper::Utils::CompareStrings(std::string str1, std::string str2)
{
	const char* string_1 = str1.c_str();
	const char* string_2 = str2.c_str();

	if (strcmp(string_1, string_2) == 0)
	{
		return true;
	}

	return false;
}

bool modhelper::Utils::CompareWideStrings(std::wstring wstr1, std::wstring wstr2)
{
	const wchar_t* wide_string_1 = wstr1.c_str();
	const wchar_t* wide_string_2 = wstr2.c_str();

	if (wcscmp(wide_string_1, wide_string_2) == 0)
	{
		return true;
	}

	return false;
}
