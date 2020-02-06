#include "face_node.h"
#include "tri_flipper.h"
size_t cg::face_node::count = 1;

cg::face_node::face_node(face* F) :data(F), isActive(true), isVisited(false)
{
	if (F != nullptr) data->SetFaceNode(this);
}

cg::face_node* cg::face_node::New(face* F)
{
	return new face_node(F);
}

size_t cg::face_node::GetCount()
{
	return count;
}

void cg::face_node::SetCount(size_t N)
{
	count = N;
}

void cg::face_node::PushChild(face_node* FN)
{
	childList.push_back(FN);
}

void cg::face_node::CreateChild(vertex* V)
{
	if (isActive && data != nullptr)
	{
		std::list<edge*> outerEdge;
		auto halfEdge = data->GetHalfEdgeVector();
		auto presentHalfEdge = *halfEdge.begin();
		for (size_t i = 0; i < halfEdge.size(); i++)
		{
			faceVertList.push_back(presentHalfEdge->GetStart());
			presentHalfEdge = presentHalfEdge->GetNext();
			outerEdge.push_back(halfEdge[i]->GetParentEdge());
		}
		isActive = false;
		for (size_t i = 0; i < halfEdge.size(); i++)
		{
			face* newFace = tri_face::New(halfEdge[i]->GetStart(), halfEdge[i]->GetEnd(), V);
			childList.push_back(New(newFace));
		}
		count += 2;
		std::unique_ptr<tri_flipper>triFlipper(new tri_flipper);
		for (auto it=outerEdge.begin();it!=outerEdge.end();it++)
		{
			triFlipper->flip(*it);
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

void cg::face_node::ActiveFlag(bool stat)
{
	isActive = stat;
}

std::list<cg::face_node*>& cg::face_node::GetChildList()
{
	return childList;
}

void cg::face_node::PrintNode(std::ofstream& file)
{
	if (!isVisited)
	{
		if (isActive)
		{
			isVisited = true;
			auto halfEdgeVector = data->GetHalfEdgeVector();
			for (auto it = halfEdgeVector.begin(); it != halfEdgeVector.end(); it++)
			{
				file << (*it)->GetStart()->GetId() << " ";
			}
			file << std::endl;
		}
		else
		{
			for (auto it = childList.begin(); it != childList.end(); it++)
			{
				isVisited = true;
				(*it)->PrintNode(file);
			}
		}
	}
}

void cg::face_node::ResetIsVisitedStat()
{
}
