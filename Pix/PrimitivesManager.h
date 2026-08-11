#pragma once

#include"Vertex.h"

//purpose of this manager is to store all the verticies
//render all of the shapes based on Topology
//clip//cull all of the non visible faces



enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None, 
	Back,
	Front,
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void OnNewFrame();
	void SetCullMode(CullMode mode);


	//start accepting verteices
	bool BeginDraw(Topology topology,bool applyTransform);
	//Add vertex to manager
	void AddVertex(const Vertex& v);
	//Send all the stored vertices to render, as specified
	//by topology, to rasterizer
	void EndDraw();
private:
	PrimitivesManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	CullMode mCullMode = CullMode::None;
	bool mDrawBegin = false;
	bool mApplyTransform;
};