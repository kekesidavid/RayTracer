#pragma once
#include "GeometricObject.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"

class Triangle : public GeometricObject
{
private:

	Point3D a, b, c;
	Vector3D normal;

	bool containsPoint(const Point3D&) const;

public:

	Triangle();
	Triangle(const Triangle& triangle);
	Triangle(const Point3D& a, const Point3D& b, const Point3D& c);

	float intersect(const Ray&) const;
	Vector3D getNormal(const Point3D&) const;

	void setMaterial(const Material*);
	const Material* getMaterial(const Point3D&) const;
	Sample2D getUV(const Point3D&) const;
};