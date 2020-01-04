#pragma once
#include"essential.h"

namespace cg
{

	class vertex
	{
	public:
		static vertex* New(const double& = 0.0, const double& = 0.0, const double& = 0.0);

		vertex(const double& = 0.0, const double& = 0.0, const double& = 0.0);
		virtual ~vertex();

		void Reassign(const double& = 0.0, const double& = 0.0, const double& = 0.0);
		size_t GetId();
		double GetXCoord() const;
		double GetYCoord() const;
		double GetZCoord() const;
		void Print();

	private:
		static size_t count;
		size_t id;
		double xCoord, yCoord, zCoord;
	};
}