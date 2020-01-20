#include "sweep_line.h"
#include "convex_hull.h"
#include "face.h"

#define N 500
#define RMAX 1.0
#define M_PI 3.14159265358979323846  /* pi */
#include <ctime>
int main()
{
	/*
	//------------------------------EXAMPLE 1 (Graham Scan convex hull)
	//CREATING VERTICES AND ASSIGNING RANDOM VALUE
	std::vector<cg::vertex*>V;
	srand(static_cast<unsigned int>(time(static_cast<time_t>(0))));
	for (auto it = 0; it < N; ++it)
	{
		double radius = RMAX * static_cast<double> (rand()) / static_cast<double>(RAND_MAX);
		double theta = 2.0 * M_PI * static_cast<double> (rand()) / static_cast<double>(RAND_MAX);
		V.emplace_back(cg::vertex::New(radius * cos(theta), radius * sin(theta)));
	}

	std::list<cg::vertex*> convexHullVertexList; // LIST TO STORE POINTER TO CONVEX HULL VERTEX
	//CALLING THE CONVEX HULL FUNCTION
	//------------------------------------------
	cg::convexHull(V, convexHullVertexList);
	//------------------------------------------
	//PRINTING THE CONVEXHULL VERTICES
	for (auto it = convexHullVertexList.begin(); it != convexHullVertexList.end(); ++it)
	{
		std::cout << (*it)->GetXCoord() << " " << (*it)->GetYCoord() << std::endl;
	}
	std::cout << (*convexHullVertexList.begin())->GetXCoord() << " " << (*convexHullVertexList.begin())->GetYCoord() << std::endl;

	ClearVector<cg::vertex*>(V);










	//------------------------------EXAMPLE 2 (line intersection)

	//std::vector<cg::vertex*> vertexVec; //TO KEEP TRACK OF VERTEX MEMORY, SO THAT WE CAN DELETE IT. 
	std::vector<cg::edge*> edgeVec;

	//  SPECIFY THE LOCATION OF DATA FILE HERE
	std::string vertexFile = "../input/test.crd";

	//READING DATA FROM INPUT FILE (FORMAT OF LINE  --->      START_X    START_Y    END_X    END_Y)
	{
		std::ifstream FileIn;
		FileIn.open(vertexFile, std::ios::in);
		assert(!FileIn.fail());

		double x[4];
		while (!FileIn.eof())
		{
			FileIn >> x[0] >> x[1] >> x[2] >> x[3];

			cg::vertex* start = cg::vertex::New(x[0], x[1]);
			cg::vertex* end = cg::vertex::New(x[2], x[3]);
			edgeVec.emplace_back(cg::edge::New(start, end));
		}
		FileIn.close();
	}
	//AT THIS POINT WE'VE STORED THE POINTER OF ALL EDGES IN A STL VECTOR

// SWEEP LINE ALGORITHM CALL
//-----------------------------------------------------------------------

	cg::sweep_line(edgeVec);

	//-----------------------------------------------------------------------

		//MEMORY CLEAN UP
	for (auto it = edgeVec.begin(); it != edgeVec.end(); it++)
	{
		auto vertStart = (*it)->GetStart();
		auto vertEnd = (*it)->GetEnd();
		FREE_OBJ_MACRO(vertStart);
		FREE_OBJ_MACRO(vertEnd);
		FREE_OBJ_MACRO(*it);
	}
	*/
	cg::vertex* v[6];

	v[0] = cg::vertex::New(0 , 0 );
	v[1] = cg::vertex::New(10, 0 );
	v[2] = cg::vertex::New(0 , 5 );
	v[3] = cg::vertex::New(0 ,-10);
	v[4] = cg::vertex::New(10, -8);
	v[5] = cg::vertex::New(-5, -5);

	cg::face* tf1 = cg::tri_face::New(v[0], v[1], v[2]);
	cg::face* tf2 = cg::tri_face::New(v[0], v[1], v[3]);
	cg::face* tf3 = cg::tri_face::New(v[1], v[4], v[3]);
	cg::face* tf4 = cg::tri_face::New(v[0], v[3], v[5]);
	std::cout << tf1->GetArea() << std::endl;
	std::cout << tf2->GetArea() << std::endl;

	delete tf3;
	delete tf1;
	tf2 = nullptr;

	system("pause");
	return 0;
}