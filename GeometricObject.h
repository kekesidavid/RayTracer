#pragma once
#include "Ray.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Material.h"
#include "Sample2D.h"

class GeometricObject
{
protected:

	const Material* material;

public:

	virtual float intersect(const Ray&) const = 0;
	virtual Vector3D getNormal(const Point3D&) const = 0;

	virtual void setMaterial(const Material*) = 0;
	//FIX THIS: no need to pass a Point3D
	virtual const Material* getMaterial(const Point3D&) const = 0;
	virtual Sample2D getUV(const Point3D&) const = 0;
};