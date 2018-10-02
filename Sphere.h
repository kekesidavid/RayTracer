#pragma once
#include "GeometricObject.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"

class Sphere : public GeometricObject
{
private:

	Point3D center;
	float radius;

public:

	Sphere();
	Sphere(const Sphere&);
	Sphere(const Point3D&, float);
	
	float intersect(const Ray&) const;
	Vector3D getNormal(const Point3D&) const;

	void setMaterial(const Material*);
	const Material* getMaterial(const Point3D&) const;
	Sample2D getUV(const Point3D&) const;
};