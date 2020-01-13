#include "edge.h"

size_t cg::edge::count = 0;

cg::edge* cg::edge::New(vertex* start, vertex* end)
{
	cg::edge* newEdge = new edge(start, end);
	start->GetAssociatedEdge().push_back(newEdge);
	end->GetAssociatedEdge().push_back(newEdge);
	return newEdge;
}

cg::edge::edge(vertex* start, vertex* end) :id(count++), start(start), end(end)
{
}

cg::vector cg::edge::GetEdgeVector()
{
	return vector(start,end);
}


cg::edge::~edge()
{
	//FREE_OBJ_MACRO(halfEdge);
	//std::cout << "edge deleted" << std::endl;
}

void cg::edge::FlipVertex()
{
	vertex* temp = start;
	start = end;
	end = temp;
}

size_t cg::edge::GetId()
{
	return id;
}

cg::vertex* cg::edge::GetStart()
{
	return start;
}

cg::vertex* cg::edge::GetEnd()
{
	return end;
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
