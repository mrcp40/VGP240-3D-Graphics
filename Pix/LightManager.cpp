#include "LightManager.h"
#include "MaterialManager.h"
#include "LightType.h"

LightManager* LightManager::Get()
{
	static LightManager sInstance;
	return &sInstance;
}
void LightManager::OnNewFrame()
{
	mLights.clear();
	mAmbient = X::Colors::White;
	mDiffuse = X::Colors::White;
	mSpecular = X::Colors::White;
}

void LightManager::SetLightAmbient(const X::Color& color)
{
	mAmbient = color;
}

void LightManager::SetLightDiffuse(const X::Color& color)
{
	mDiffuse = color;
}

void LightManager::SetLightSpecular(const X::Color& color)
{
	mSpecular = color;
}

void LightManager::AddDirectionaleLight(const Vector3& direction)
{
	auto light = std::make_unique<DirectionaleLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetDirection(direction);
	mLights.push_back(std::move(light));
}

void LightManager::AddPointLight(const Vector3& position, float kConstant, float kLinear, float kQuadratic)
{
	auto light = std::make_unique<PointLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetPosition(position);
	light->SetAttenuation(kConstant, kLinear, kQuadratic);
	mLights.push_back(std::move(light));
}

X::Color LightManager::ComputeLightColor(const Vector3& position, const Vector3& normal)
{
	if (mLights.empty())
	{
		return X::Colors::White;
	}
	//C=Ce+E(Ca+Cd+Cs)
	X::Color color = MaterialManager::Get()->GetMaterialEmissive();
	for (auto& Light : mLights)
	{
		color += Light->ComputeLightColor(position, normal);
	}
	return color;
}
