#pragma once
#include"Command.h"

class CmdEndDraw :public Command
{
public:
	const char* GetName() override
	{
		return "EndDraw";
	}

	const char* GetDescription() override
	{
		return
			"Enddraw()\n"
			"- send the vertices to rasterizer to render\n";
	}
	bool Execute(const std::vector<std::string>& params) override;
};