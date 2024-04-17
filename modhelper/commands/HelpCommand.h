#pragma once

#include "BaseCommand.h"

class HelpCommand : public BaseCommand {
public:

    HelpCommand(const wchar_t* call_name)
        : BaseCommand(call_name)
    {

    }
    int RunCommand();
};