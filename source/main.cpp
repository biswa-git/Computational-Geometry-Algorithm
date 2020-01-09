#include "sweep_line.h"
#include "bst.h"
//#define VERT_NUM 8
#define EDGE_NUM 8


int main()
{
	std::vector<cg::vertex*> vertexVec;
	std::vector<cg::vertex*>::iterator vertexrIt;

	vertexVec.push_back(cg::vertex::New(0, 4));
	vertexVec.push_back(cg::vertex::New(2, 8));

	vertexVec.push_back(cg::vertex::New(7, 7));
	vertexVec.push_back(cg::vertex::New(0, 5));
	
	vertexVec.push_back(cg::vertex::New(5, 1));
	vertexVec.push_back(cg::vertex::New(2, 7));
	
	vertexVec.push_back(cg::vertex::New(4, 8));
	vertexVec.push_back(cg::vertex::New(0, 2));
	
	vertexVec.push_back(cg::vertex::New(2, 5));
	vertexVec.push_back(cg::vertex::New(6, 7));

	vertexVec.push_back(cg::vertex::New(3, 4));
	vertexVec.push_back(cg::vertex::New(9, -1));
	
	vertexVec.push_back(cg::vertex::New(14, -3));
	vertexVec.push_back(cg::vertex::New(5, 2));

	vertexVec.push_back(cg::vertex::New(-2, 9));
	vertexVec.push_back(cg::vertex::New(4, 7));

	std::vector<cg::edge*> edgeVec;
	std::vector<cg::edge*>::iterator edgeIt;

	vertexrIt = vertexVec.begin();
	for (size_t i = 0; i < EDGE_NUM; i++)
	{
		edgeVec.emplace_back(cg::edge::New(vertexVec[2 * i], vertexVec[2 * i + 1]));
	}

	cg::sweep_line(edgeVec);

	ClearVector<cg::edge*>(edgeVec);
	ClearVector<cg::vertex*>(vertexVec);
	return 0;
}