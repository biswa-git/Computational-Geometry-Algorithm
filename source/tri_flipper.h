#pragma once
#include "essential.h"
#include "face_node.h"
namespace cg
{
	class tri_flipper
	{
	public:
		void flip(edge*);
	private:
		static std::set<edge*> edgeSet;
	};
}