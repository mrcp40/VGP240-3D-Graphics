#pragma once

#include "Command.h"

class CmdSetAddressMode:public Command
{
public:
	const char* GetName()override
	{
		return "SetAddressMode";
	}
	const char* GetDescription() override
	{
		return
			"SetAddressMode(addressMode)\n "
			"\n"
			"- Border sets a color \n"
			"- Clamp maintain edge \n"
			"- Wrap repeats uv color\n"
			"- Mirror flips and repeats uv color\n";
	}
	bool Execute(const std::vector<std::string>& params)override;
};