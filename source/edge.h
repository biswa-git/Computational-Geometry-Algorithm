#pragma once
#include "vector.h"
#include "vertex.h"
#include "face.h"
#include "math.h"
namespace cg
{
	class half_edge;
	class face;
	class edge
	{
	public:
		friend class edge;
		static edge* New(vertex*, vertex*);
		~edge();
		edge(edge const&) = delete;
		edge& operator=(edge const&) = delete;
		void Flip();
		size_t GetId();
		vertex* GetStart();
		vertex* GetEnd();
		vector GetVector();
		half_edge* GetHalfEdge(const size_t&);
		static void Legalize(edge*);
	private:
		edge(vertex*, vertex*);

		static size_t count;
		size_t id;

		vertex* start;
		vertex* end;

		half_edge* halfEdge[2];
	};

	class half_edge
	{
	public:
		static half_edge* New(edge*, vertex*);
		~half_edge() = default;
		half_edge(half_edge const&) = delete;
		half_edge& operator=(half_edge const&) = delete;
		edge* GetParentEdge();
		vertex* GetStart();
		vertex* GetEnd();
		void SetNext(half_edge*);
		half_edge* GetNext();
		void SetFace(face*);
		face* GetFace();
		vector GetEdgeVector();

	private:
		half_edge(edge*, vertex*);
		edge* parent;
		vertex* start;
		face* associatedFace;
		half_edge* next;
	};
}
