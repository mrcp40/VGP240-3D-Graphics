#include"PrimitivesManager.h"
#include"Rasterizer.h"


PrimitivesManager::PrimitivesManager()
{

}

PrimitivesManager* PrimitivesManager::Get()
{
	static PrimitivesManager sInstance;
	return &sInstance;
}
bool PrimitivesManager::BeginDraw(Topology topology)
{
	mVertexBuffer.clear();
	mTopology = topology;
	mDrawBegin = true;
	return true;
}
void PrimitivesManager::AddVertex(const Vertex& v)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(v);
	}
}
void PrimitivesManager::EndDraw()
{
	if (!mDrawBegin)
	{
		return;
	}

	switch (mTopology)
	{
	case Topology::Point:
	{
		for (uint32_t i = 0; i < mVertexBuffer.size(); ++i)
		{
			Rasterizer::Get()->DrawPoints(mVertexBuffer[i]);
		}
	}
		break;
	case Topology::Line:
	{
		for (uint32_t i = 1; i < mVertexBuffer.size(); i+=2)
		{
			Rasterizer::Get()->DrawLines(mVertexBuffer[i - 1], mVertexBuffer[i]);
		}
	}
		break;
	case Topology::Triangle:
	{
		for (uint32_t i = 2; i < mVertexBuffer.size(); i+=3)
		{
			Rasterizer::Get()->DrawTriangles(mVertexBuffer[i-2],mVertexBuffer[i-1],mVertexBuffer[i]);
		}
	}
		break;
	default:
		break;
	}
}