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
		void operator =(const edge&);
		void FlipVertex();
		size_t GetId();
		vertex* GetStart();
		vertex* GetEnd();
		vector* GetVector() const;
		void TopStart();
	private:
		edge(vertex*, vertex*);
		static size_t count;
		size_t id;
		vertex* start;
		vertex* end;
		vector* halfEdge;
	};
}



