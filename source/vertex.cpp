#include "vertex.h"

size_t cg::vertex::count = 0;

cg::vertex::vertex(const double& x, const double& y, const double& z):id(count++),xCoord(x), yCoord(y), zCoord(z)
{
}

cg::vertex* cg::vertex::New(const double& x, const double& y, const double& z)
{
	return new vertex(x,y,z);
}

cg::vertex::~vertex()
{
	//std::cout << "vertex deleted with id: " << id << std::endl;
}

void cg::vertex::Reassign(const double& x, const double& y, const double& z)
{
	xCoord = x;
	yCoord = y;
	zCoord = z;
}

size_t cg::vertex::GetId() const
{
	return id;
}

double cg::vertex::GetXCoord() const
{
	return xCoord;
}

double cg::vertex::GetYCoord() const
{
	return yCoord;
}

double cg::vertex::GetZCoord() const
{
	return zCoord;
}

std::set<cg::edge*>& cg::vertex::GetAssociatedEdge()
{
	return AssociatedEdge;
}

void cg::vertex::Print() const
{
	std::cout << "id:" << id << " [" << xCoord << "," << yCoord << "," << zCoord << "]" << std::endl;
}

double cg::CrossProductByVertex2D(vertex* A, vertex* B, vertex* C)
{
	return (B->GetXCoord() - A->GetXCoord()) * (C->GetYCoord() - B->GetYCoord()) -
		   (B->GetYCoord() - A->GetYCoord()) * (C->GetXCoord() - B->GetXCoord());
}