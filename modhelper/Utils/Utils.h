#pragma once

#include <string>
#include <stdarg.h>
#include <cube/cube.h>

#define MAX_MESSAGE_LENGTH 1024

typedef enum BTN_CMB
{
	OK_CANCEL,
	YES_NO,
};

namespace modhelper
{
	namespace Utils
	{
		//Wait for further implementation
		//This needs to be re-declared in another file, i recommend doing so in the Modloader Header or Translation files since we will be 
		//Setting its value there.
		//extern bool _loaded;

		extern inline void Print(std::string format, ...);
		extern inline void ShowMessage(std::string fmt_message, ...);
		extern inline bool ShowPrompt(std::string fmt_message, ...);

		//extern inline bool HasGameLoaded() { return _loaded; };
	}
}