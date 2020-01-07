#include "edge.h"
#include "bst.h"
#define VERT_NUM 6
#define EDGE_NUM 5
int main()
{
	BST<int> test;
	test.insert(34);
	test.insert(35);
	test.insert(33);
	test.insert(34);
	test.insert(35);
	test.insert(23);
	test.insert(37);
	test.insert(38);
	test.insert(36);
	std::vector<cg::vertex*> vertexVec;
	std::vector<cg::vertex*>::iterator vertexrIt;

	vertexVec.push_back(cg::vertex::New(0, 4));
	vertexVec.push_back(cg::vertex::New(2, 8));

	vertexVec.push_back(cg::vertex::New(7, 7));
	vertexVec.push_back(cg::vertex::New(0, 5));

	vertexVec.push_back(cg::vertex::New(6, 1));
	vertexVec.push_back(cg::vertex::New(2, 7));

	vertexVec.push_back(cg::vertex::New(4, 8));
	vertexVec.push_back(cg::vertex::New(0, 2));

	vertexVec.push_back(cg::vertex::New(2, 7));
	vertexVec.push_back(cg::vertex::New(6, 1));

	std::vector<cg::edge*> edgeVec;
	std::vector<cg::edge*>::iterator edgeIt;

	vertexrIt = vertexVec.begin();
	for (size_t i = 0; i < EDGE_NUM; i++)
	{
		edgeVec.emplace_back(cg::edge::New(vertexVec[2 * i], vertexVec[2 * i + 1]));
		edgeVec[i]->TopStart();
	}

	ClearVector<cg::edge*>(edgeVec);
	ClearVector<cg::vertex*>(vertexVec);

	cg::vertex* v1 = cg::vertex::New(1, 1);
	cg::vertex* v2 = cg::vertex::New(0, 0);
	v2 = v1;
	v2->Print();

	return 0;
}