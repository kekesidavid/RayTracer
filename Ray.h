#pragma once
#include "Point3D.h"
#include "Vector3D.h"

class Ray
{
private:

	Point3D origin;
	Vector3D direction;

public:

	Ray();
	Ray(const Ray&);
	Ray(const Point3D&, Vector3D&);
	Ray(const Point3D&, const Point3D&);

	Ray& operator=(const Ray&);
	friend std::ostream& operator<<(std::ostream &, const Ray&);

	Point3D getOrigin() const;
	Vector3D getDirection() const;
	Point3D getPointAt(float) const;
	Ray getReflectedRay(const Point3D&, const Vector3D&) const;
	Ray getRefractedRay(const Point3D&, const Vector3D&, float) const;
};