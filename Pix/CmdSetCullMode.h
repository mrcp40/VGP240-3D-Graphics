#pragma once

#include "Command.h"

class CmdSetCullMode:public Command
{
public:
	const char* GetName() override
	{
		return "SetCullMode";
	}
	const char* GetDescription() override
	{
		return
			"SetCullMode(mode)\n"
			"\n"
			"- sets cull mode for rendering\n"
			"- <none>: no cull mode use\n"
			"- <back>: cull faces pointed away from cameras\n"
			"- <front>: cull faces pointed to the cameras\n";
	}
	bool Execute(const std::vector<std::string>& params)override;
private:

};