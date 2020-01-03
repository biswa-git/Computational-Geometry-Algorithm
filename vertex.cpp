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
}

void cg::vertex::Reassign(const double& x, const double& y, const double& z)
{
	xCoord = x;
	yCoord = y;
	zCoord = z;
}

size_t cg::vertex::GetId()
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

void cg::vertex::Print()
{
	std::cout << "id:" << id << " [" << xCoord << "," << yCoord << "," << zCoord << "]" << std::endl;
}
