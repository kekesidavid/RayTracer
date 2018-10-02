#pragma once
#include <iostream>
#include "Vector3D.h"

class Point3D
{
private:

	float x, y, z;
	
public:

	Point3D();
	Point3D(const Point3D&);
	Point3D(float, float, float);

	Point3D& operator=(const Point3D&);
	Point3D operator+(const Vector3D&) const;
	Vector3D operator-(const Point3D&) const;
	friend std::ostream& operator<<(std::ostream &, const Point3D&);

	float getDistanceTo(const Point3D&) const;
};