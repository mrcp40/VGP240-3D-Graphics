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

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	//start accepting verteices
	bool BeginDraw(Topology topology);
	//Add vertex to manager
	void AddVertex(const Vertex& v);
	//Send all the stored vertices to render, as specified
	//by topology, to rasterizer
	void EndDraw();
private:
	PrimitivesManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	bool mDrawBegin = false;
};