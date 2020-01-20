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
		vertex(vertex const&) = delete;
		vertex& operator=(vertex const&) = delete;

		void Reassign(const double& = 0.0, const double& = 0.0, const double& = 0.0);
		size_t GetId() const;
		double GetXCoord() const;
		double GetYCoord() const;
		double GetZCoord() const;
		std::set<edge*>& GetAssociatedEdge();
		void Print() const;

	private:
		vertex(const double& = 0.0, const double& = 0.0, const double& = 0.0);

		static size_t count;
		size_t id;
		double xCoord, yCoord, zCoord;
		std::set<edge*> AssociatedEdge;
	};

	double CrossProductByVertex2D(vertex*, vertex*, vertex*);
}