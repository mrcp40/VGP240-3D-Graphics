#pragma once

#include "Command.h"

class CmdCorrectUV :public Command
{
public:
	const char* GetName()override
	{
		return"CorrectUV";
	}
	const char* GetDescription()override
	{
		return
			"CorrectUV(coorectUV)\n"
			"\n"
			"- enable/disable uv correction when using texture\n";
	}
	bool Execute(const std::vector<std::string>& params) override;
};