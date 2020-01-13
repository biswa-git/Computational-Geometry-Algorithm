#pragma once
#include "vertex.h"
#include "vector.h"

namespace cg
{
	bool compareAngle(cg::vertex*, cg::vertex*);
	void convexHull(std::vector<cg::vertex*>&, std::list<cg::vertex*>&);
}
