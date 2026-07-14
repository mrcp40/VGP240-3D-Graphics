#pragma once
#include"Command.h"

class CmdSetFillMode:public Command
{
public:
	const char* GetName() override
	{
		return "SetFillMode";
	}
	const char* GetDescription() override
	{
		return
			"SetFillMode(fillmode)\n"
			"\n"
			"- set triangle fill mode(wireframe,solid)\n";
	}
	bool Execute(const std::vector<std::string>& params);

};
