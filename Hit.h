#pragma once
#include "Vector3D.h"
#include "Point3D.h"
#include "GeometricObject.h"
#include "Material.h"

class Hit
{
private:

	const GeometricObject* hitObject;
	Point3D hitPoint;
	Vector3D inDir;
	Vector3D normal;

public:

	Hit();
	Hit(const Hit&);
	Hit(const GeometricObject*, const Point3D&, const Vector3D&);
	Hit(const GeometricObject*, const Ray&, float);

	const GeometricObject* getHitObject() const;
	Point3D getHitPoint() const;
	Vector3D getNormal() const;
	Vector3D getInDir() const;
	const Material* getMaterial() const;
};