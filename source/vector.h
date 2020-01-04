#pragma once
#include "vertex.h"

namespace cg
{
	class vector
	{
	public:
		static vector* New(const double& = 0.0, const double& = 0.0, const double& = 0.0);
		static vector* New(const vertex&, const vertex&);
		static vector* New(vertex*, vertex*);

		vector(vertex*, vertex*);
		vector(const vertex&, const vertex&);
		vector(const double& = 0.0, const double& = 0.0, const double& = 0.0);
		virtual ~vector();

		vector operator+(const vector&);
		vector operator-(const vector&);
		double operator*(const vector&); // DOT PRODUCT
		double operator^(const vector&); // CROSS PRODUCT
		double abs();

		double GetDx();
		double GetDy();
		double GetDz();

		void Reassign(vertex*, vertex*);
		void Reassign(const vertex&, const vertex&);
		void Reassign(double = 0.0, double = 0.0, double = 0.0);

		void Print() const;

	private:
		double dx, dy, dz;
	};
}