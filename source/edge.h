#pragma once
#include "vector.h"
#include "vertex.h"
namespace cg
{
	class edge
	{
	public:
		static edge* New(vertex*, vertex*);
		edge(vertex*, vertex*);
		~edge();
		void FlipVertex();
		vector* GetVector() const;
		void TopStart();
	private:
		vertex* start;
		vertex* end;
		vector* halfEdge;
	};
}



