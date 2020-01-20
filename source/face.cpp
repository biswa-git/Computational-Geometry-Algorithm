#include "face.h"

size_t cg::face::count = 0;

cg::face::face() :area(0.0)
{
}

cg::face::~face()
{
}

cg::tri_face* cg::tri_face::New(vertex* A, vertex* B, vertex* C)
{
	return new tri_face(A,B,C);
}

cg::tri_face::~tri_face()
{
	for (size_t i = 0; i < 3; i++)
	{	
		auto parentEdge = halfEdge[i]->GetParentEdge();
		halfEdge[i]->SetNext(nullptr);
		halfEdge[i]->SetFace(nullptr);
		if (parentEdge->GetHalfEdge(0)->GetFace() == nullptr && parentEdge->GetHalfEdge(1)->GetFace() == nullptr)
		{	
			//DELETE THE EDGE IF IT IS ORPHANED. i.e. NO ASSOCIATED FACES.
			delete parentEdge;
		}
	}
}

double cg::tri_face::GetArea()
{
	return area;
}

cg::tri_face::tri_face(vertex* A, vertex* B, vertex* C) :halfEdge{ nullptr, nullptr, nullptr }
{
	//IF IT IS COLINEAR THEN IT IS NOT A VALID SURFACE. WE NEED TO STOP THAT.
	auto lhs = (A->GetYCoord() - B->GetYCoord()) / (A->GetXCoord() - B->GetXCoord());
	auto rhs = (A->GetYCoord() - C->GetYCoord()) / (A->GetXCoord() - C->GetXCoord());
	if (lhs == rhs || abs(lhs - rhs) < 1e-12)
	{
		std::cout << "The points of the triangles are colinear! Aborting..." << std::endl;
		exit(1);
	}

	//	FIRST WE CREATE THREE EDGE / CHECK EXISTANCE

	vertex* tempVertexArray[3]{ A,B,C };
	edge* triEdge[3]{ nullptr,nullptr,nullptr };

	//CHECKING WHETHER EDGE EXIST BETWEEN VERTEX 0 AND 1
	{
		auto edgeList = tempVertexArray[0]->GetAssociatedEdge();
		for (auto it = edgeList.begin(); it != edgeList.end(); it++)
		{
			auto associatedEdge = *it;
			if (associatedEdge->GetEnd() == tempVertexArray[1]  || associatedEdge->GetStart() == tempVertexArray[1])
			{
				triEdge[0] = associatedEdge;
				break;
			}
		}
		if (triEdge[0] == nullptr) triEdge[0] = edge::New(tempVertexArray[0], tempVertexArray[1]);
	}
	//CHECKING WHETHER EDGE EXIST BETWEEN VERTEX 1 AND 2
	{
		auto edgeList = tempVertexArray[1]->GetAssociatedEdge();
		for (auto it = edgeList.begin(); it != edgeList.end(); it++)
		{
			auto associatedEdge = *it;
			if (associatedEdge->GetEnd() == tempVertexArray[2] || associatedEdge->GetStart() == tempVertexArray[2])
			{
				triEdge[1] = associatedEdge;
				break;
			}
		}
		if (triEdge[1] == nullptr) triEdge[1] = edge::New(tempVertexArray[1], tempVertexArray[2]);
	}

	//CHECKING WHETHER EDGE EXIST BETWEEN VERTEX 2 AND 0
	{
		auto edgeList = tempVertexArray[2]->GetAssociatedEdge();
		for (auto it = edgeList.begin(); it != edgeList.end(); it++)
		{
			auto associatedEdge = *it;
			if (associatedEdge->GetEnd() == tempVertexArray[0] || associatedEdge->GetStart() == tempVertexArray[0])
			{
				triEdge[2] = associatedEdge;
				break;
			}
		}
		if (triEdge[2] == nullptr) triEdge[2] = edge::New(tempVertexArray[2], tempVertexArray[0]);
	}

	for (size_t i = 0; i < 3; i++)
	{
		vector directionVec(triEdge[i]->GetHalfEdge(0)->GetEnd(), tempVertexArray[(i+2)%3]);

		if ((triEdge[i]->GetHalfEdge(0)->GetEdgeVector() ^ directionVec) > 0.0)
		{
			halfEdge[i] = triEdge[i]->GetHalfEdge(0);
		}
		else
		{
			halfEdge[i] = triEdge[i]->GetHalfEdge(1);
		}
		halfEdge[i]->SetFace(this);
	}

	if (halfEdge[0]->GetEnd() == halfEdge[1]->GetStart())
	{
		halfEdge[0]->SetNext(halfEdge[1]);
		halfEdge[1]->SetNext(halfEdge[2]);
		halfEdge[2]->SetNext(halfEdge[0]);
	}
	else
	{
		halfEdge[0]->SetNext(halfEdge[2]);
		halfEdge[2]->SetNext(halfEdge[1]);
		halfEdge[1]->SetNext(halfEdge[0]);
	}
	//AREA BEING A BASIC PROPERTY OF FACE, BEING CALCULATED IMMIDIATELY
	CalculateArea();
}

void cg::tri_face::CalculateArea()
{
	vector firstEdgeVector(halfEdge[0]->GetStart(), halfEdge[0]->GetEnd());
	vector secondEdgeVector(halfEdge[1]->GetStart(), halfEdge[1]->GetEnd());
	area = 0.5*abs(firstEdgeVector ^ secondEdgeVector);
}
