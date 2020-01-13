#include "vector.h"

cg::vector::vector(vertex* vStart, vertex* vEnd)
{
	dx = vEnd->GetXCoord() - vStart->GetXCoord();
	dy = vEnd->GetYCoord() - vStart->GetYCoord();
	dz = vEnd->GetZCoord() - vStart->GetZCoord();
}

cg::vector::vector(const double& dx, const double& dy, const double& dz) :dx(dx), dy(dy), dz(dz)
{
	//std::cout << "vector created" << std::endl;
}

cg::vector* cg::vector::New(const double& dx, const double& dy, const double& dz)
{
	return new cg::vector(dx,dy,dz);
}

cg::vector* cg::vector::New(vertex* vStart, vertex* vEnd)
{
	return new cg::vector(vStart, vEnd);
}

cg::vector::~vector()
{
	//std::cout << "vector deleted" << std::endl;
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

double cg::vector::Abs()
{
	return sqrt(dx * dx + dy * dy + dz * dz);
}

double cg::vector::GetDx() const
{
	return dx;
}

double cg::vector::GetDy() const
{
	return dy;
}

double cg::vector::GetDz() const
{
	return dz;
}

void cg::vector::Reassign(vertex* vStart, vertex* vEnd)
{
	dx = vEnd->GetXCoord() - vStart->GetXCoord();
	dy = vEnd->GetYCoord() - vStart->GetYCoord();
	dz = vEnd->GetZCoord() - vStart->GetZCoord();

}

void cg::vector::Reassign(const double& dx, const double& dy, const double& dz)
{
	this->dx = dx;
	this->dy = dy;
	this->dz = dz;
}

void cg::vector::Print() const
{
	std::cout << "[" << dx << "," << dy << "," << dz << "]" << std::endl;
}
