#include "convex_hull.h"
// global data to reduce space complexity while sorting
cg::vertex* leftMostVertex;

bool compareAngle(cg::vertex* A, cg::vertex* B)
{
	cg::vector vectorA(leftMostVertex, A);
	double leftMostVertex_to_A = asin((vectorA.GetDy()) / vectorA.Abs());
	cg::vector vectorB(leftMostVertex, B);
	double leftMostVertex_to_B = asin((vectorB.GetDy()) / vectorB.Abs());

	//this step ensure the leftmost vertex remain in the first position
	if (A == leftMostVertex) leftMostVertex_to_A = -2.0;
	if (B == leftMostVertex) leftMostVertex_to_B = -2.0;

	return leftMostVertex_to_A < leftMostVertex_to_B;
	if (leftMostVertex_to_A == leftMostVertex_to_B) return vectorA.Abs() < vectorB.Abs();
	return false;
}

void convexHull(std::vector<cg::vertex*>& V, std::list<cg::vertex*>& convexHullVertexList)
{
	//cg::vertex* firstVertex = nullptr;
	{
		//FINDING THE LEFTMOST POINTS ID  O(n)
		double leftPos = (*V.begin())->GetXCoord();
		for (auto it = V.begin(); it != V.end(); ++it)
		{
			if ((*it)->GetXCoord() < leftPos)
			{
				leftPos = (*it)->GetXCoord();
				leftMostVertex = (*it);
			}
		}
	}

	std::sort(V.begin(), V.end(), compareAngle);
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
			cg::vertex* present = convexHullVertexList.back(); convexHullVertexList.pop_back();
			cg::vertex* prev    = *convexHullVertexList.rbegin();
			cg::vertex* next    = *it;
			
			if (cg::CrossProductByVertex2D(prev,present,next) > 0.0) // ^ IS OVERLOADED TO PERFORM CROSS PRODUCT
			{
				convexHullVertexList.push_back(present);
				contd = false;
			}
		}
		convexHullVertexList.push_back(*it);
	}
}
