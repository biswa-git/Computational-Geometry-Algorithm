#include "edge.h"
size_t cg::edge::count = 0;

cg::edge* cg::edge::New(vertex* start, vertex* end)
{
	cg::edge* newEdge = new edge(start, end);
	start->GetAssociatedEdge().insert(newEdge);
	end->GetAssociatedEdge().insert(newEdge);
	//std::cout << "new edge " << newEdge->GetId() << " created" << std::endl;
	return newEdge;
}

cg::edge::~edge()
{
	//std::cout << "edge " << this->GetId() << " deleted" << std::endl;
	start->GetAssociatedEdge().erase(this);
	end->GetAssociatedEdge().erase(this);
	delete halfEdge[0];
	delete halfEdge[1];
}

cg::edge::edge(vertex* start, vertex* end) :id(count++), start(start), end(end)
{
	halfEdge[0] = cg::half_edge::New(this, start);
	halfEdge[1] = cg::half_edge::New(this, end);
}

void cg::edge::Flip()
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

cg::vector cg::edge::GetVector()
{
	return vector(start,end);
}

cg::half_edge* cg::edge::GetHalfEdge(const size_t& index)
{
	return halfEdge[index];
}

void cg::edge::Legalize(edge* E)
{
	//THIS ROUTINE RECURSIVELY FLIP & LEGALIZE THE DELAUNEY TRIANGLE
	std::queue<edge*> edgeQueue;
	edgeQueue.push(E);
	while (edgeQueue.size() != 0)
	{
		edge* tempEdge = edgeQueue.back(); edgeQueue.pop();
		half_edge* tempHalfEdge[2]{ tempEdge->GetHalfEdge(0),tempEdge->GetHalfEdge(1) };
		face* face[2]{ tempHalfEdge[0]->GetFace(),tempHalfEdge[1]->GetFace() };
		if (face[0] != nullptr && face[1] != nullptr)
		{
            /*------------------------------------------
                           B
                           /\
                          /  \
                         /    \
                        /--->--\		
                        \--<---/ A
                         \    /
                          \  /
                           \/
                           D
            --------------------------------------------*/
			//NOW WE TEST WHTHER THE EDGE IS LEGAL OR NOT
			vertex* A = tempHalfEdge[0]->GetEnd();
			vertex* B = tempHalfEdge[0]->GetNext()->GetEnd();
			vertex* C = tempHalfEdge[0]->GetStart();
			vertex* D = tempHalfEdge[1]->GetNext()->GetEnd();
		
			double ADx = A->GetXCoord() - D->GetXCoord();
			double BDx = B->GetXCoord() - D->GetXCoord();
			double CDx = C->GetXCoord() - D->GetXCoord();
			double ADy = A->GetYCoord() - D->GetYCoord();
			double BDy = B->GetYCoord() - D->GetYCoord();
			double CDy = C->GetYCoord() - D->GetYCoord();
			
			double M[3][3]
			{
				{ADx, ADy, ADx * ADx + ADy * ADy},
				{BDx, BDy, BDx * BDx + BDy * BDy},
				{CDx, CDy, CDx * CDx + CDy * CDy}
			};

			double det = cg::math::det(M);
			if (det > 0.0)
			{
				//FLIP EDGE AND LEGALISE OTHER EDGES 
				std::cout << "EDGE FLIP NEED TO BE PERFORMED" << std::endl;
			}
		}
	}
}

cg::half_edge* cg::half_edge::New(edge* E, vertex* V)
{
	return new half_edge(E,V);
}

cg::edge* cg::half_edge::GetParentEdge()
{
	return parent;
}

cg::vertex* cg::half_edge::GetStart()
{
	return start;
}

cg::vertex* cg::half_edge::GetEnd()
{
	if (start == parent->GetStart()) return parent->GetEnd();
	else return parent->GetStart();
}

void cg::half_edge::SetNext(half_edge* HE)
{
	next = HE;
}

cg::half_edge* cg::half_edge::GetNext()
{
	return next;
}

void cg::half_edge::SetFace(face* F)
{
	associatedFace = F;
}

cg::face* cg::half_edge::GetFace()
{
	return associatedFace;
}

cg::vector cg::half_edge::GetEdgeVector()
{
	return vector(start,GetEnd());
}

cg::half_edge::half_edge(edge* E, vertex* V) :parent(E), start(V), next(nullptr), associatedFace(nullptr)
{
	//ctor
}
