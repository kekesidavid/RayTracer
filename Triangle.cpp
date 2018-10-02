#include "Triangle.h"
#include "GeometricObject.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"
#include "AppConstants.h"

Triangle::Triangle()
{
}

Triangle::Triangle(const Triangle& triangle) 
	: a(triangle.a), b(triangle.b), c(triangle.c), normal(triangle.normal)
{
}

Triangle::Triangle(const Point3D& a, const Point3D& b, const Point3D& c) 
	: a(a), b(b), c(c)
{
	normal = CrossProduct((b - a), (c - a));
	normal.normalize();
}

float Triangle::intersect(const Ray& ray) const
{
	Vector3D va = a - ray.getOrigin();
	Vector3D viewDir = ray.getDirection();
	viewDir.normalize();

	float numerator = DotProduct(va, normal);
	float denominator = DotProduct(viewDir, normal);
	float t = numerator / denominator;

	Point3D intersection = ray.getOrigin() + (viewDir * t);
	if (containsPoint(intersection))
	{
		return t;
	}
	else
	{
		return appconst::MISS;
	}
}

bool Triangle::containsPoint(const Point3D& ip) const
{
	Vector3D ab = b - a;
	Vector3D bc = c - b;
	Vector3D ca = a - c;

	Vector3D ap = ip - a;
	Vector3D bp = ip - b;
	Vector3D cp = ip - c;

	if (DotProduct(CrossProduct(ab, ap), normal) < 0) return false;
	if (DotProduct(CrossProduct(bc, bp), normal) < 0) return false;
	if (DotProduct(CrossProduct(ca, cp), normal) < 0) return false;

	return true;
}

Vector3D Triangle::getNormal(const Point3D& ip) const
{
	return normal;
}

void Triangle::setMaterial(const Material* mat)
{
	material = mat;
}

const Material* Triangle::getMaterial(const Point3D&) const
{
	return material;
}

Sample2D Triangle::getUV(const Point3D& hitPoint) const
{
	return { 0, 0 };
}

