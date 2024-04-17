#pragma once
#include <string>
#include <functional>
#include "cube/cube.h"

class BaseCommand {
public:
	const wchar_t* call_name;
	void* func_call;

	BaseCommand(const wchar_t* call_name);
	void setFunction(void* func_call);
	virtual int RunCommand();

private:
};