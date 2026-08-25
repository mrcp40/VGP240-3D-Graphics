#include "LightType.h"
#include "MaterialManager.h"
#include "Camera.h"


X::Color DirectionaleLight::ComputeLightColor(const Vector3& position, const Vector3& nromal)
{
	Camera* camre = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();


	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	Vector3 L = -mDirection;
	float dot = X::Math::Max(MathHelper::Dot(L, nromal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot;

	Vector3 v = MathHelper::Normalize(camre->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, nromal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOff;

	return ambient + diffuse + specular;
}

void DirectionaleLight::SetDirection(const Vector3& direction)
{
	mDirection = MathHelper::Normalize(direction);
}


X::Color PointLight::ComputeLightColor(const Vector3& position, const Vector3& nromal)
{
	Camera* camre = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	// get distance from light
	Vector3 L = mPosition - position;
	float distance = MathHelper::Magnitude(L);
	L /= distance;

	// calculate light intensity
	float attenuation = 1.0f / (mKConstant + (mKLinear * distance) + (mKQuadratic * distance * distance));
	float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);

	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	float dot = X::Math::Max(MathHelper::Dot(L, nromal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

	Vector3 v = MathHelper::Normalize(camre->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, nromal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOff * iL;

	return ambient + diffuse + specular;
}

void PointLight::SetPosition(const Vector3& position)
{
	mPosition = position;
}

void PointLight::SetAttenuation(float kConstant, float kLinear, float kQuadratic)
{
	mKConstant = kConstant;
	mKLinear = kLinear;
	mKQuadratic = kQuadratic;
}

X::Color SpotLight::ComputeLightColor(const Vector3& position, const Vector3& nromal)
{
	Camera* camre = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	// get distance from light
	Vector3 L = mPosition - position;
	float distance = MathHelper::Magnitude(L);
	L /= distance;

	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	// check to see if position is in the cone
	Vector3 lightDir = -L;
	float dotDir = MathHelper::Dot(lightDir, mDirection);
	if (dotDir < mCosAngle)
	{
		return ambient;
	}

	// calculate light intensity
	float spot = pow(dotDir, mDecay);
	float attenuation = spot / (mKConstant + (mKLinear * distance) + (mKQuadratic * distance * distance));
	float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);


	float dot = X::Math::Max(MathHelper::Dot(L, nromal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

	Vector3 v = MathHelper::Normalize(camre->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOff = X::Math::Max((float)pow(MathHelper::Dot(r, nromal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOff * iL;

	return ambient + diffuse + specular;
}

void SpotLight::SetPosition(const Vector3& position)
{
	mPosition = position;
}

void SpotLight::SetDirection(const Vector3& direction)
{
	mDirection = direction;
}

void SpotLight::SetAttenuation(float kConstant, float kLinear, float kQuadratic)
{
	mKConstant = kConstant;
	mKLinear = kLinear;
	mKQuadratic = kQuadratic;
}

void SpotLight::SetAngle(float angle)
{
	mCosAngle =cos(angle);
}

void SpotLight::SetDecay(float decay)
{
	mDecay = decay;
}