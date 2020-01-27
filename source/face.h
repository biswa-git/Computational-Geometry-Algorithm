#pragma once
#include "edge.h"
namespace cg
{
	class half_edge;
	class face
	{
	public:
		face();
		virtual ~face();
		face(face const&) = delete;
		face& operator=(face const&) = delete;
		virtual double GetArea() = 0;
		virtual void SetOrphanedEdgeRemoveFlag(bool);
		virtual std::vector<half_edge*>& GetHalfEdgeVector() = 0;
		virtual bool IsInside(vertex*) = 0;
	protected:
		virtual void CalculateArea() = 0;
		static size_t count;
		double area;
		bool isOrphanedEdgeRemoveFlag;
		std::vector<half_edge*> halfEdge;
	};

	class tri_face :public face
	{
	public:
		static tri_face* New(vertex*, vertex*, vertex*);
		~tri_face();
		virtual double GetArea();
		virtual std::vector<half_edge*>& GetHalfEdgeVector();
		virtual bool IsInside(vertex*);
	protected:
		virtual void CalculateArea();
	private:
		tri_face(vertex*, vertex*, vertex*);
	};
}
