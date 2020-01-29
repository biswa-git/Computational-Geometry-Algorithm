#include "face.h"

size_t cg::face::count = 0;

cg::face::face() :area(0.0), isOrphanedEdgeRemoveFlag{ true }, faceNode(nullptr)
{
}

cg::face::~face()
{
}

void cg::face::SetOrphanedEdgeRemoveFlag(bool status)
{
	isOrphanedEdgeRemoveFlag = status;
}

void cg::face::SetFaceNode(face_node* FN)
{
	faceNode = FN;
}

cg::face_node* cg::face::GetFaceNode()
{
	return faceNode;
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
		if (isOrphanedEdgeRemoveFlag && parentEdge->GetHalfEdge(0)->GetFace() == nullptr && parentEdge->GetHalfEdge(1)->GetFace() == nullptr)
		{	
			//DELETE THE EDGE IF IT IS ORPHANED. i.e. NO ASSOCIATED WITH ANY FACE/FACES.
			delete parentEdge;
		}
	}
}

double cg::tri_face::GetArea()
{
	return area;
}

cg::tri_face::tri_face(vertex* A, vertex* B, vertex* C)
{
	halfEdge.resize(3, nullptr);
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

	//CHECKING WHETHER EDGE EXIST BETWEEN VERTEX
	for (size_t i = 0; i < 3; i++)
	{
		auto edgeList = tempVertexArray[i]->GetAssociatedEdge();
		for (auto it = edgeList.begin(); it != edgeList.end(); it++)
		{
			auto associatedEdge = *it;
			if (associatedEdge->GetEnd() == tempVertexArray[(i + 1) % 3] || associatedEdge->GetStart() == tempVertexArray[(i + 1) % 3])
			{
				triEdge[i] = associatedEdge;
				break;
			}
		}
		if (triEdge[i] == nullptr) triEdge[i] = edge::New(tempVertexArray[i], tempVertexArray[(i + 1) % 3]);
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

std::vector<cg::half_edge*>& cg::tri_face::GetHalfEdgeVector()
{
	return halfEdge;
}

bool cg::tri_face::IsInside(vertex* V)
{
	for (size_t i = 0; i < 3; i++)
	{
		double crossProduct = cg::CrossProductByVertex2D(halfEdge[i]->GetStart(), halfEdge[i]->GetEnd(), V);
		if (crossProduct <= 0.0) return false;
	}
	return true;
}
