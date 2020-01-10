#include "edge.h"

size_t cg::edge::count = 0;

cg::edge* cg::edge::New(vertex* start, vertex* end)
{
	cg::edge* newEdge = new edge(start, end);
	start->GetAssociatedEdge().push_back(newEdge);
	end->GetAssociatedEdge().push_back(newEdge);
	return newEdge;
}

cg::edge::edge(vertex* start, vertex* end) :id(count++), start(start), end(end), halfEdge(nullptr)
{
	halfEdge = cg::vector::New(start, end);
}


cg::edge::~edge()
{
	FREE_OBJ_MACRO(halfEdge);
	//std::cout << "edge deleted" << std::endl;
}

void cg::edge::operator = (const cg::edge& rValue)
{
	start = rValue.start;
	end = rValue.end;
	if (halfEdge == nullptr) halfEdge = cg::vector::New(); //cautionary step DeepCopy
	*halfEdge = *rValue.halfEdge;
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
