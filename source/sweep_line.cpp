#include "sweep_line.h"

bool cg::CustomVertexEdgePairComparator(const std::pair<cg::vertex*, cg::edge*>& pair1, const std::pair<cg::vertex*, cg::edge*>& pair2)
{
	if (pair1.first->GetYCoord() == pair2.first->GetYCoord()) return (pair1.first->GetXCoord() < pair2.first->GetXCoord());
	else return (pair1.first->GetYCoord() > pair2.first->GetYCoord());
}

void cg::sweep_line(std::vector<cg::edge*>& edgeVec)
{
	std::vector<std::pair<cg::vertex*, cg::edge*>> eventList;
	for (auto it = edgeVec.begin(); it != edgeVec.end(); it++)
	{
		eventList.emplace_back((*it)->GetStart(), *it);
		eventList.emplace_back((*it)->GetEnd(), *it);
	}

	std::sort(eventList.begin(), eventList.end(), CustomVertexEdgePairComparator);

	std::set<cg::edge*> edgeset;
	for (auto it = eventList.begin(); it != eventList.end(); it++)
	{
		if (edgeset.find(it->second) != edgeset.end())
		{
			edgeset.erase(it->second);
		}
		else
		{
			double crossProd[4];
			for (auto edgeSetIt = edgeset.begin(); edgeSetIt != edgeset.end(); edgeSetIt++)
			{
				cg::vertex* latestEdgeStartVertex = it->second->GetStart();
				cg::vertex* latestEdgeEndVertex = it->second->GetEnd();
				cg::vertex* edgeSetItStartVertex = (*edgeSetIt)->GetStart();
				cg::vertex* edgeSetItEndVertex = (*edgeSetIt)->GetEnd();

				crossProd[0] = cg::CrossProductByVertex2D(latestEdgeStartVertex, latestEdgeEndVertex, edgeSetItStartVertex);
				crossProd[1] = cg::CrossProductByVertex2D(latestEdgeStartVertex, latestEdgeEndVertex, edgeSetItEndVertex);

				crossProd[2] = cg::CrossProductByVertex2D(edgeSetItStartVertex, edgeSetItEndVertex, latestEdgeStartVertex);
				crossProd[3] = cg::CrossProductByVertex2D(edgeSetItStartVertex, edgeSetItEndVertex, latestEdgeEndVertex);

				if (crossProd[0] * crossProd[1] <= 0 && crossProd[2] * crossProd[3] <= 0)
				{
					std::cout << "intersection detected! between " << it->second->GetId() << " and " << (*edgeSetIt)->GetId() << std::endl;
				}
			}
			edgeset.insert(it->second);
		}
	}
};