#include "tri_flipper.h"
std::set<cg::edge*> cg::tri_flipper::edgeSet;
void cg::tri_flipper::flip(edge* E)
{
	//THIS ROUTINE RECURSIVELY FLIP & LEGALIZE THE DELAUNEY TRIANGLE
	edgeSet.insert(E);
	while (edgeSet.size() != 0)
	{
		edge* tempEdge = *edgeSet.begin();
		edgeSet.erase(tempEdge);
		half_edge* tempHalfEdge[2]{ tempEdge->GetHalfEdge(0),tempEdge->GetHalfEdge(1) };
		face* tmpFace[2]{ tempHalfEdge[0]->GetFace(),tempHalfEdge[1]->GetFace() };

		if (tmpFace[0] != nullptr && tmpFace[1] != nullptr)
		{
            /*------------------------------------------
                           B
                           /\
                          /  \
                         /    \
                        /--->--\
                      C \--<---/ A
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
				tmpFace[0]->GetFaceNode()->ActiveFlag(false);
				tmpFace[1]->GetFaceNode()->ActiveFlag(false);

				edgeSet.insert(tempHalfEdge[0]->GetNext()->GetParentEdge());
				edgeSet.insert(tempHalfEdge[0]->GetNext()->GetNext()->GetParentEdge());
				edgeSet.insert(tempHalfEdge[1]->GetNext()->GetParentEdge());
				edgeSet.insert(tempHalfEdge[1]->GetNext()->GetNext()->GetParentEdge());

				cg::face* newFace[2]{ nullptr,nullptr };
				newFace[0] = tri_face::New(A, B, D);
				newFace[1] = tri_face::New(B, C, D);

				face_node* faceNode[2]{ nullptr,nullptr };
				faceNode[0] = face_node::New(newFace[0]);
				faceNode[1] = face_node::New(newFace[1]);

				tmpFace[0]->GetFaceNode()->PushChild(faceNode[0]);
				tmpFace[0]->GetFaceNode()->PushChild(faceNode[1]);

				tmpFace[1]->GetFaceNode()->PushChild(faceNode[0]);
				tmpFace[1]->GetFaceNode()->PushChild(faceNode[1]);
				//auto count = face_node::GetCount();
				//face_node::SetCount(count + 2);
				//FLIP EDGE AND LEGALISE OTHER EDGES 
				//std::cout << "EDGE FLIP NEED TO BE PERFORMED" << std::endl;

			}
		}
	}

}
