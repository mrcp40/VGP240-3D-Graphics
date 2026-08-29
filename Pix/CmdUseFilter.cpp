#include "CmdUseFilter.h"
#include "VariableCache.h"
#include "TextureManager.h"

bool CmdUseFilter::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	bool useFilter = VariableCache::Get()->GetBool(params[0]);
	TextureManager::Get()->SetFilter(useFilter);

	return false;
}
