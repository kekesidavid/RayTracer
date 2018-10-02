#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"

Point3D::Point3D() 
	: x(0), y(0), z(0)
{
}

Point3D::Point3D(const Point3D& p) 
	: x(p.x), y(p.y), z(p.z)
{
}

Point3D::Point3D(float x, float y, float z) 
	: x(x), y(y), z(z)
{
}

Point3D& Point3D::operator=(const Point3D& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
}

Point3D Point3D::operator+(const Vector3D& vec) const
{
	return Point3D(x + vec.getX(), y + vec.getY(), z + vec.getZ());
}

Vector3D Point3D::operator-(const Point3D& p) const
{
	return Vector3D(x - p.x, y - p.y, z - p.z);
}

std::ostream& operator<<(std::ostream& os, const Point3D& p)
{
	os << "Point3D[" << p.x << ";" << p.y << ";" << p.z << "]";
	return os;
}

float Point3D::getDistanceTo(const Point3D& p) const
{
	float a = p.x - x;
	float b = p.y - y;
	float c = p.z - z;
	return sqrt(a*a + b * b + c * c);
}