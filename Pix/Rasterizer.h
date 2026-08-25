#pragma once

#include <XEngine.h>
#include"Vertex.h"

enum class FillMode
{
	WireFrame,
	Solid
};

enum class ShadeMode
{
	Flat,
	Gouraud,
	Phong
};

class Rasterizer
{
public:
	static Rasterizer* Get();

public:
	void SetColor(X::Color color);
	void SetFillMode(FillMode fillMode);
	void DrawPoint(int x, int y);
	void SetShadeMode(ShadeMode shadeMode);
	ShadeMode GetShadeMode() const;


	void DrawPoints(const Vertex& v);
	void DrawLines(const Vertex& a, const Vertex& b);
	void DrawTriangles(const Vertex& a, const Vertex& b, const Vertex& c);

private:
	void DrawFilledTriangle(const Vertex& a, const Vertex& b, const Vertex& c);
	X::Color mColor = X::Colors::White;
	FillMode mFillmode = FillMode::WireFrame;
	ShadeMode mShadeMode = ShadeMode::Phong;
};