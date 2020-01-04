#include "edge.h"

cg::edge::edge(const vertex& start, const vertex& end) :start(start), end(end)
{
	halfEdge.Reassign(start, end);
}

cg::edge::~edge()
{
}

void cg::edge::FlipVertex()
{
	vertex temp = start;
	start = end;
	end = temp;
	halfEdge.Reassign(start, end);
}

cg::vector cg::edge::GetVector()
{
	return halfEdge;
}

void cg::edge::TopStart()
{
	std::cout << start.GetYCoord() << " " << end.GetYCoord();
	if (end.GetYCoord() > start.GetYCoord())
	{
		FlipVertex();
		std::cout << " edge is flipped to " << start.GetYCoord() << " " << end.GetYCoord();
	}
	std::cout << std::endl;
}

