#pragma once
#include "vector.h"

namespace cg
{
	class edge
	{
	public:
		edge(const vertex&, const vertex&);
		~edge();
		void FlipVertex();
		vector GetVector();
		void TopStart();
	private:
		vertex start;
		vertex end;
		vector halfEdge;
	};
}



