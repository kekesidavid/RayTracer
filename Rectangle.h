#pragma once
#include "GeometricObject.h"
#include "Triangle.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"
#include "Texture.h"
#include "Sample2D.h"

class Rectangle : public GeometricObject
{
private:

	float width;
	float height;
	Point3D position;

	Vector3D normal;
	Vector3D up;
	Vector3D right;

	Triangle triangle1;
	Triangle triangle2;

	void calculateDirections();
	void generateTriangles();

public:

	Rectangle();
	Rectangle(float, float, const Point3D&, const Vector3D&);
	Rectangle(const Rectangle& triangle);
	
	float intersect(const Ray&) const;
	Vector3D getNormal(const Point3D&) const;

	void setMaterial(const Material*);
	const Material* getMaterial(const Point3D&) const;
	Sample2D getUV(const Point3D&) const;
};