#pragma once
#include"essential.h"
namespace cg
{
	class edge;
	class vertex
	{
	public:
		static vertex* New(const double& = 0.0, const double& = 0.0, const double& = 0.0);
		virtual ~vertex();

		void Reassign(const double& = 0.0, const double& = 0.0, const double& = 0.0);
		size_t GetId() const;
		double GetXCoord() const;
		double GetYCoord() const;
		double GetZCoord() const;
		std::vector<edge*>& GetAssociatedEdge();
		void Print() const;

	private:
		vertex(const double& = 0.0, const double& = 0.0, const double& = 0.0);

		static size_t count;
		size_t id;
		double xCoord, yCoord, zCoord;
		std::vector<edge*> AssociatedEdge;
	};
}