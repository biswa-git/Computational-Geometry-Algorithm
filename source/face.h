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
	protected:
		virtual void CalculateArea() = 0;
		static size_t count;
		double area;
	};

	class tri_face :public face
	{
	public:
		static tri_face* New(vertex*, vertex*, vertex*);
		~tri_face();
		virtual double GetArea();
	protected:
		virtual void CalculateArea();
	private:
		tri_face(vertex*, vertex*, vertex*);
		half_edge* halfEdge[3];
	};
}
