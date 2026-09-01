#include "CmdPostProcessing.h"
#include "PostProcessing.h"

bool CmdPostProcessingBeginDraw::Execute(const std::vector<std::string>& params)
{
	PostProcessing::Get()->BeginDraw();
	return true;
}

bool CmdPostProcessingEndDraw::Execute(const std::vector<std::string>& params)
{
	PostProcessing::Get()->EndDraw();
	return true;
}

bool CmdPostProcessingSetEffectType::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	EffectType effectType = EffectType::None;
	if (params[0] == "None") { effectType = EffectType::None; }
	else if (params[0] == "Monochrome") { effectType = EffectType::Monochrome; }
	else if (params[0] == "Invert") { effectType = EffectType::Invert; }
	else if (params[0] == "Mirror") { effectType = EffectType::Mirror; }
	else if (params[0] == "Blur") { effectType = EffectType::Blur; }
	else if (params[0] == "ColorMaskR") { effectType = EffectType::ColorMaskR; }
	else if (params[0] == "ColorMaskG") { effectType = EffectType::ColorMaskG; }
	else if (params[0] == "ColorMaskB") { effectType = EffectType::ColorMaskB; }
	else if (params[0] == "Sepia") { effectType = EffectType::Sepia; }
	else if (params[0] == "Wave") { effectType = EffectType::Wave; }
	else if (params[0] == "ChromaticBerration") { effectType = EffectType::ChromaticBerration; }
	else { return false; }
	PostProcessing::Get()->SetEffectType(effectType);
	return true;
}
