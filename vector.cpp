#include "vector.h"

cg::vector::vector(vertex* vStart, vertex* vEnd)
{
	dx = vEnd->GetXCoord() - vStart->GetXCoord();
	dy = vEnd->GetYCoord() - vStart->GetYCoord();
	dz = vEnd->GetZCoord() - vStart->GetZCoord();
}

cg::vector::vector(const vertex& vStart, const vertex& vEnd)
{
	dx = vEnd.GetXCoord() - vStart.GetXCoord();
	dy = vEnd.GetYCoord() - vStart.GetYCoord();
	dz = vEnd.GetZCoord() - vStart.GetZCoord();
}

cg::vector::vector(const double& dx, const double& dy, const double& dz) :dx(dx), dy(dy), dz(dz)
{
}

cg::vector* cg::vector::New(const double& dx, const double& dy, const double& dz)
{
	return new vector(dx,dy,dz);
}

cg::vector* cg::vector::New(const vertex& vStart, const vertex& vEnd)
{
	return new vector(vStart,vEnd);
}

cg::vector* cg::vector::New(vertex* vStart, vertex* vEnd)
{
	return new vector(vStart, vEnd);
}

cg::vector::~vector()
{
}

cg::vector cg::vector::operator+(const vector& V)
{
	return vector(this->dx + V.dx, this->dy + V.dy, this->dz + V.dz);
}

cg::vector cg::vector::operator-(const vector& V)
{
	return vector(this->dx - V.dx, this->dy - V.dy, this->dz - V.dz);
}

double cg::vector::operator*(const vector& V)
{
	return (this->dx * V.dx + this->dy * V.dy + this->dz * V.dz);
}

//3d implementatin needed
double cg::vector::operator^(const vector& V)
{
	return (this->dx * V.dy - this->dy * V.dx);
}

double cg::vector::abs()
{
	return sqrt(dx * dx + dy * dy + dz * dz);
}

double cg::vector::GetDx()
{
	return dx;
}

double cg::vector::GetDy()
{
	return dy;
}

double cg::vector::GetDz()
{
	return dz;
}

void cg::vector::Reassign(vertex* vStart, vertex* vEnd)
{
	dx = vEnd->GetXCoord() - vStart->GetXCoord();
	dy = vEnd->GetYCoord() - vStart->GetYCoord();
	dz = vEnd->GetZCoord() - vStart->GetZCoord();

}

void cg::vector::Reassign(const vertex& vStart, const vertex& vEnd)
{
	dx = vEnd.GetXCoord() - vStart.GetXCoord();
	dy = vEnd.GetYCoord() - vStart.GetYCoord();
	dz = vEnd.GetZCoord() - vStart.GetZCoord();

}

void cg::vector::Reassign(double dx, double dy, double dz)
{
	this->dx = dx;
	this->dy = dy;
	this->dy = dz;
}

void cg::vector::Print() const
{
	std::cout << "[" << dx << "," << dy << "," << dz << "]" << std::endl;
}
