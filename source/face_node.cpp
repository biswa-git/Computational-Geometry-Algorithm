#include "face_node.h"

cg::face_node::face_node(face* F) :data(F), isActive(true)
{
}

cg::face_node* cg::face_node::New(face* F)
{
	return new face_node(F);
}

void cg::face_node::PushChild(face_node* FN)
{
	childList.push_back(FN);
}

void cg::face_node::CreateChild(vertex* V)
{
	if (isActive && data != nullptr)
	{
		auto halfEdge = data->GetHalfEdgeVector();
		auto presentEdge = *halfEdge.begin();
		for (size_t i = 0; i < halfEdge.size(); i++)
		{
			faceVertList.push_back(presentEdge->GetStart());
			presentEdge = presentEdge->GetNext();
		}
		//data->SetOrphanedEdgeRemoveFlag(false);
		//FREE_OBJ_MACRO(data); //this delete the face //need to check for memory leak
		isActive = false;
		for (size_t i = 0; i < halfEdge.size(); i++)
		{
			face* newFace = tri_face::New(halfEdge[i]->GetStart(), halfEdge[i]->GetEnd(), V);
			childList.push_back(New(newFace));
		}
	}
	else
	{
		for (auto it = childList.begin(); it != childList.end(); it++)
		{
			if ((*it)->data->IsInside(V))
			{
				(*it)->CreateChild(V);
				break;
			}
		}
	}
}
