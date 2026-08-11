#include "CmdMatrixStack.h"
#include "MatrixStack.h"
#include "VariableCache.h"

bool CmdPushTranslation::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	const float x = vc->GetFloat(params[0]);
	const float y = vc->GetFloat(params[1]);
	const float z = vc->GetFloat(params[2]);
	MatrixStack::Get()->PushTranslation({ x, y, z });
	return true;
}

bool CmdPushRoationX::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	float degrees = VariableCache::Get()->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationX(degrees * MathHelper::DegToRad);
	return true;
}

bool CmdPushRoationY::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	float degrees = VariableCache::Get()->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationY(degrees * MathHelper::DegToRad);
	return true;
}

bool CmdPushRoationZ::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	float degrees = VariableCache::Get()->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationZ(degrees * MathHelper::DegToRad);
	return true;
}

bool CmdPushScaling::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	const float x = vc->GetFloat(params[0]);
	const float y = vc->GetFloat(params[1]);
	const float z = vc->GetFloat(params[2]);
	MatrixStack::Get()->PushScalling({ x, y, z });
	return true;
}

bool CmdPopMatrix::Execute(const std::vector<std::string>& params)
{
	MatrixStack::Get()->PopMatrix();
	return true;
}