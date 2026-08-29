#pragma once

#include "Command.h"

class CmdUseFilter :public Command
{
public:
	const char* GetName()override
	{
		return"SetUseFilter";
	}
	const char* GetDescription() override
	{
		return "SetUseFilter(useFilter)\n"
			"\n"
			"- enable/disable using bilinear filter on texture\n";
	}
	bool Execute(const std::vector<std::string>& params)override;
};