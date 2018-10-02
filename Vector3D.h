#pragma once
#include <iostream>

class Vector3D
{
private:

	float x, y, z;
	
public:

	Vector3D();
	Vector3D(const Vector3D&);
	Vector3D(float, float, float);

	void normalize();
	
	Vector3D& operator=(const Vector3D&);
	Vector3D operator+(const Vector3D&) const;
	Vector3D operator-(const Vector3D&) const;
	Vector3D operator*(float) const;
	friend std::ostream& operator<<(std::ostream &, const Vector3D&);

	float getX() const;
	float getY() const;
	float getZ() const;

	friend Vector3D CrossProduct(const Vector3D&, const Vector3D&);
	friend float DotProduct(const Vector3D&, const Vector3D&);
	friend float CosTheta(const Vector3D&, const Vector3D&);
};