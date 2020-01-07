#include "edge.h"

cg::edge* cg::edge::New(vertex* start, vertex* end)
{
	return new edge(start,end);
}

cg::edge::edge(vertex* start, vertex* end) :start(start), end(end), halfEdge(nullptr)
{
	halfEdge = cg::vector::New(start, end);
}


cg::edge::~edge()
{
	FreeObjMacro(halfEdge);
	std::cout << "edge deleted" << std::endl;
}

void cg::edge::FlipVertex()
{
	vertex* temp = start;
	start = end;
	end = temp;
	if (halfEdge != nullptr)
	{
		halfEdge->Reassign(-halfEdge->GetDx(), -halfEdge->GetDy());
	}
}

cg::vector* cg::edge::GetVector() const
{
	return halfEdge;
}

void cg::edge::TopStart()
{
	std::cout << start->GetYCoord() << " " << end->GetYCoord();
	if (end->GetYCoord() > start->GetYCoord())
	{
		FlipVertex();
		std::cout << " edge is flipped to " << start->GetYCoord() << " " << end->GetYCoord();
	}
	std::cout << std::endl;
}

