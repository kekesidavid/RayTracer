#include <iostream>
#include "Vector3D.h"

Vector3D::Vector3D() 
	: x(0), y(0), z(0)
{
}

Vector3D::Vector3D(const Vector3D& vec) 
	: x(vec.x), y(vec.y), z(vec.z)
{
}

Vector3D::Vector3D(float x, float y, float z) 
	: x(x), y(y), z(z)
{
}

void Vector3D::normalize()
{
	float invLength = 1.0f / sqrt(x * x + y * y + z * z);
	x *= invLength;
	y *= invLength;
	z *= invLength;
}

Vector3D& Vector3D::operator=(const Vector3D& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

Vector3D Vector3D::operator+(const Vector3D& vec) const
{
	return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D Vector3D::operator-(const Vector3D& vec) const
{
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D Vector3D::operator*(float m) const
{
	return Vector3D(x * m, y * m, z * m);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
{
	os << "Vector3D[" << vec.x << ";" << vec.y << ";" << vec.z << "]";
	return os;
}

float Vector3D::getX() const
{
	return x;
}

float Vector3D::getY() const
{
	return y;
}

float Vector3D::getZ() const
{
	return z;
}

Vector3D CrossProduct(const Vector3D& left, const Vector3D& right)
{
	float rx = left.y * right.z - left.z * right.y;
	float ry = left.z * right.x - left.x * right.z;
	float rz = left.x * right.y - left.y * right.x;
	return Vector3D(rx, ry, rz);
}

float DotProduct(const Vector3D& left, const Vector3D& right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

float CosTheta(const Vector3D& left, const Vector3D& right)
{
	float cosTheta = DotProduct(left, right);
	if (cosTheta < 0) cosTheta = 0;
	return cosTheta;
}