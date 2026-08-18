#pragma once

#include "Light.h"

class DirectionaleLight:public Light
{
public:
	X::Color ComputeLightColor(const Vector3& position, const Vector3& nromal) override;
	void SetDirection(const Vector3& direction);

private:
	Vector3 mDirection = { 0.0f,0.0f,1.0f };
};

class PointLight :public Light
{
public:
	X::Color ComputeLightColor(const Vector3& position, const Vector3& nromal) override;
	void SetPosition(const Vector3& position);
	void SetAttenuation(float kConstant, float kLinear, float kQuadratic);

private:
	Vector3 mPosition = { 0.0f,0.0f,1.0f };
	float mKConstant = 1.0f;
	float mKLinear = 0.0f;
	float mKQuadratic = 0.0f;
};