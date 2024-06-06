#pragma once

#include <string>
#include <stdarg.h>
#include <cube/cube.h>

#define MAX_MESSAGE_LENGTH 1024

namespace modhelper
{
	namespace Utils
	{
		//Wait for further implementation
		//This needs to be re-declared in another file, i recommend doing so in the Modloader Header or Translation files since we will be 
		//Setting its value there.
		//extern bool _loaded;

		//Prints to the GAME Chat
		extern inline void Print(std::string format, ...);

		//Shows a Message using the Windows API (WinAPI)
		extern inline void ShowMessage(std::string fmt_message, ...);

		//Shows a Prompt using the Windows API (WinAPI)
		extern inline bool ShowPrompt(std::string fmt_message, ...);

		//Transforms a String (std::string) into a Wide Character String (std::wstring)
		extern inline std::wstring String_2_WString(std::string str);

		//Transforms a Wide Character String (std::wstring) into a String (std::string)
		extern inline std::string WString_2_String(std::wstring wstr);

		//Compare a pair of Strings and returns true if they're are equal to each other
		extern inline bool CompareStrings(std::string str1, std::string str2);

		//Compare a pair of Wide Character Strings and returns true if they're are equal to each other
		extern inline bool CompareWideStrings(std::wstring wstr1, std::wstring wstr2);

		//extern inline bool HasGameLoaded() { return _loaded; };
	}
}