#include "Rasterizer.h"
#include "DepthBuffer.h"
#include "LightManager.h"
#include "TextureManager.h"
#include "PostProcessing.h"



//slope <= 1
//left is smaller x position, right is the bigger one
void DrawLineHorizontal(const Vertex& left, const Vertex& right)
{
	float dx = right.pos.x - left.pos.x;
	int startX = static_cast<int>(left.pos.x);
	int endX = static_cast<int>(right.pos.x);
	for (int x = startX; x <= endX; ++x)
	{
		float t = static_cast<float>(x - startX) / dx;
		Vertex v = LerpVertex(left, right, t);
		Rasterizer::Get()->DrawPoints(v);
	}
}

//slope >1
void DrawLineVerical(const Vertex& low, const Vertex& high)
{
	float dy = high.pos.y - low.pos.y;
	int startY = static_cast<int>(low.pos.y);
	int endY = static_cast<int>(high.pos.y);
	for (int y = startY; y <= endY; ++y)
	{
		float t = static_cast<float>(y - startY) / dy;
		Vertex v = LerpVertex(low, high, t);
		Rasterizer::Get()->DrawPoints(v);
	}
}

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;
	return &sInstance;
}

void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::SetFillMode(FillMode fillMode)
{
	mFillmode = fillMode;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::SetShadeMode(ShadeMode shadeMode)
{
	mShadeMode = shadeMode;
}

ShadeMode Rasterizer::GetShadeMode() const
{
	return mShadeMode;
}

void Rasterizer::DrawPoints(const Vertex& v)
{
	if (DepthBuffer::Get()->CheckDepthBuffer(v.pos.x, v.pos.y, v.pos.z))
	{
		X::Color pixelColor = TextureManager::Get()->SampleColor(v.color);
		if (mShadeMode == ShadeMode::Phong)
		{
			pixelColor *= LightManager::Get()->ComputeLightColor(v.worldPos, v.norm);
		}
		if (!PostProcessing::Get()->Draw(v.pos.x, v.pos.y, pixelColor))
		{
			X::DrawPixel(v.pos.x, v.pos.y, pixelColor);
		}
	}
}

void Rasterizer::DrawLines(const Vertex& a, const Vertex& b)
{
	float dx = b.pos.x - a.pos.x;
	float dy = b.pos.y - a.pos.y;

	if (MathHelper::CheckEqual(dx, 0.0f) || abs(dy / dx) > 1.0f)
	{
		if (a.pos.y < b.pos.y)
		{
			DrawLineVerical(a, b);
		}
		else
		{
			DrawLineVerical(b, a);
		}
	}
	else
	{
		if (a.pos.x < b.pos.x)
		{
			DrawLineHorizontal(a, b);
		}
		else
		{
			DrawLineHorizontal(b, a);
		}
	}

}

void Rasterizer::DrawTriangles(const Vertex& a, const Vertex& b, const Vertex& c)
{
	switch (mFillmode)
	{
	case FillMode::WireFrame:
	{
		DrawLines(a, b);
		DrawLines(b, c);
		DrawLines(c, a);
	}
	break;
	case FillMode::Solid:
	{
		std::vector<Vertex> sortedVertex = { a,b,c };
		std::sort(sortedVertex.begin(), sortedVertex.end(),
			[](const Vertex& lhs, const Vertex& rhs)
			{
				return lhs.pos.y < rhs.pos.y;
			});
		DrawFilledTriangle(sortedVertex[0], sortedVertex[1], sortedVertex[2]);
	}
	break;
	default:
		break;
	}
}

void Rasterizer::DrawFilledTriangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
	float dy = c.pos.y - a.pos.y;

	if (MathHelper::CheckEqual(a.pos.y, b.pos.y))
	{
		int startY = static_cast<int>(a.pos.y);
		int endY = static_cast<int>(c.pos.y);
		for (int y = startY; y <= endY; ++y)
		{
			float t = static_cast<float>(y - startY) / dy;
			Vertex aSide = LerpVertex(a, c, t);
			Vertex bSide = LerpVertex(b, c, t);
			DrawLines(aSide, bSide);
		}
	}
	else if (MathHelper::CheckEqual(c.pos.y, b.pos.y))
	{
		int startY = static_cast<int>(a.pos.y);
		int endY = static_cast<int>(c.pos.y);
		for (int y = startY; y <= endY; ++y)
		{
			float t = static_cast<float>(y - startY) / dy;
			Vertex bSide = LerpVertex(a, b, t);
			Vertex cSide = LerpVertex(a, c, t);
			DrawLines(bSide, cSide);
		}
	}
	else
	{
		float t = (b.pos.y - a.pos.y) / dy;
		Vertex splitVertex = LerpVertex(a, c, t);
		DrawFilledTriangle(a, b, splitVertex);
		DrawFilledTriangle(b, splitVertex, c);
	}
}
