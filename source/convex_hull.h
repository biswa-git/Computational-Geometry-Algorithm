#pragma once
#include "vertex.h"
#include "vector.h"

bool compareAngle(cg::vertex*, cg::vertex*);
void convexHull(std::vector<cg::vertex*>&, std::list<cg::vertex*>&);