#include "convex_hull.h"

void convexHull(std::vector<cg::vertex*>& V, std::list<cg::vertex*>& convexHullVertexList)
{
	cg::vertex* firstVertex = nullptr;
	{
		//FINDING THE LEFTMOST POINTS ID  O(n)
		double leftPos = (*V.begin())->GetXCoord();
		for (auto it = V.begin(); it != V.end(); ++it)
		{
			if ((*it)->GetXCoord() < leftPos)
			{
				leftPos = (*it)->GetXCoord();
				firstVertex = (*it);
			}
		}
	}

	//SORTING THE POINTS IN COUNTERCLOCKWISE DIR
	std::set<std::pair<double, cg::vertex*>> angleVertexPair;
	for (auto it = V.begin(); it != V.end(); it++)
	{
			cg::vector vec(firstVertex, *it);
			double angleWithLeftMostVertex = asin((vec.GetDy()) / vec.abs());
			if (*it == firstVertex) angleWithLeftMostVertex = -2.0;
			angleVertexPair.emplace(angleWithLeftMostVertex, *it);
	}
	//V.clear();
	auto VecIter = V.begin();
	for (auto it = angleVertexPair.begin(); it != angleVertexPair.end(); ++it)
	{
		*VecIter = it->second;
		++VecIter;
	}
	angleVertexPair.clear();

	/*-----------------------------------------------------
		WE NEED TO ADD FEW ADDITIONAL CHECKS FOR CORNER 
		CASES. WHICH I WILL ADD LATER :)
	-----------------------------------------------------*/

	//PUSHING THE VERTEX
	convexHullVertexList.push_back(*(V.begin()));
	convexHullVertexList.push_back(*(V.begin()+1));

	for (auto it = V.begin()+2; it != V.end(); ++it)
	{
		bool contd{ true };
		while(contd)
		{
			//GETTINT THE POINTER OF PAST, PRES, NEXT VERTEX
			cg::vertex* present = convexHullVertexList.back();
			convexHullVertexList.pop_back();
			cg::vertex* prev = convexHullVertexList.back();
			convexHullVertexList.pop_back();
			cg::vertex* next = *it;

			//FORMING EDGE IN THE FORM OF VECTOR
			cg::vector firstEdge(prev, present);
			cg::vector secondEdge(present, next);
			
			convexHullVertexList.push_back(prev);
			if ((firstEdge ^ secondEdge) > 0.0) // ^ IS OVERLOADED TO PERFORM CROSS PRODUCT
			{
				convexHullVertexList.push_back(present);
				contd = false;
			}
		}
		convexHullVertexList.push_back(*it);
	}
}
