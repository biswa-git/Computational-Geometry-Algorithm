#pragma once
#include"essential.h"
#include "edge.h"
namespace cg
{
	bool CustomVertexEdgePairComparator(const std::pair<cg::vertex*, cg::edge*>& pair1, const std::pair<cg::vertex*, cg::edge*>& pair2);
	void sweep_line(std::vector<cg::edge*>& edgeVec);
}