#pragma once

#include "Command.h"

class CmdPostProcessingBeginDraw :public Command
{
public:
	const char* GetName()override
	{
		return "PostProcessingBeginDraw";
	}
	const char* GetDescription()override
	{
		return
			"PostProcessingBeginDraw()\n"
			"\n"
			"- initiates rendering to render target instead of to the main screen";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPostProcessingEndDraw :public Command
{
public:
	const char* GetName()override
	{
		return "PostProcessingEndDraw";
	}
	const char* GetDescription()override
	{
		return
			"PostProcessingEndDraw()\n"
			"\n"
			"- draws the render target to the screen\n"
			"- applies set effect to the image";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPostProcessingSetEffectType :public Command
{
public:
	const char* GetName()override
	{
		return "PostProcessingSetEffectType";
	}
	const char* GetDescription()override
	{
		return
			"PostProcessingSetEffectType(effectType)\n"
			"\n"
			"- sets the effect to apply to image\n"
			"- none, monochrome, invert, mirror, blur\n"
			"- colormaskr, colormaskg, colormaskb\n"
			"- sepia, wave";
	}
	bool Execute(const std::vector<std::string>& params) override;
};