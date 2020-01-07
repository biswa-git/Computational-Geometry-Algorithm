#pragma once
#include "vector.h"
#include "vertex.h"
namespace cg
{
	class edge
	{
	public:
		static edge* New(vertex*, vertex*);
		~edge();
		void FlipVertex();
		vector* GetVector() const;
		void TopStart();
	private:
		edge(vertex*, vertex*);
		vertex* start;
		vertex* end;
		vector* halfEdge;
	};
}



