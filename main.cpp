#include "edge.h"
#include "bst.h"
#define VERT_NUM 6
#define EDGE_NUM 5
int main()
{
	BST<int> test;
	test.insert(5);
	test.insert(7);
	test.insert(52);
	test.insert(51);
	test.insert(45);
	test.insert(23);
	test.insert(16);
	test.insert(11);
	test.insert(53);
	test.insert(3);
	std::vector<cg::vertex> vertexVec;
	std::vector<cg::vertex>::iterator vertexrIt;

	vertexVec.emplace_back(0, 4);
	vertexVec.emplace_back(2, 8);

	vertexVec.emplace_back(7, 7);
	vertexVec.emplace_back(0, 5);

	vertexVec.emplace_back(6, 1);
	vertexVec.emplace_back(2, 7);

	vertexVec.emplace_back(4, 8);
	vertexVec.emplace_back(0, 2);

	vertexVec.emplace_back(2, 7);
	vertexVec.emplace_back(6, 1);

	std::vector<cg::edge> edgeVec;
	std::vector<cg::edge>::iterator edgeIt;

	vertexrIt = vertexVec.begin();
	for (size_t i = 0; i < EDGE_NUM; i++)
	{
		edgeVec.emplace_back(vertexVec[2 * i], vertexVec[2 * i + 1]);
		(edgeVec.end()-1)->TopStart();
	}
	vertexVec.clear();
	std::cout << vertexVec.size() << std::endl;
}