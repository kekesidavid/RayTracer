#include "Rectangle.h"
#include "Triangle.h"
#include "GeometricObject.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"
#include "AppConstants.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(float width, float height, const Point3D& position, const Vector3D& norm)
	: width(width), height(height), position(position), normal(norm)
{
	normal.normalize();
	calculateDirections();
	generateTriangles();
}

Rectangle::Rectangle(const Rectangle& rectangle)
	: width(rectangle.width), height(rectangle.height), position(rectangle.position), normal(rectangle.normal)
{
	calculateDirections();
	generateTriangles();
}

void Rectangle::calculateDirections()
{
	//direction is parallel with axis z
	if (DotProduct(Vector3D(0, 1, 0), normal) == 0)
	{
		right = CrossProduct(Vector3D(0, 1, 0), normal);
	}
	else
	{
		right = CrossProduct(Vector3D(0, 0, 1), normal);
	}
	right.normalize();

	up = CrossProduct(normal, right);
	up.normalize();
}

void Rectangle::generateTriangles()
{
	Point3D a = position;
	Point3D b = a + right * width;
	Point3D c = b + up * height;
	Point3D d = a + up * height;

	triangle1 = Triangle(a, b, c);
	triangle2 = Triangle(a, c, d);
}

float Rectangle::intersect(const Ray& ray) const
{
	float t = triangle1.intersect(ray);
	if (t != appconst::MISS) return t;
	t = triangle2.intersect(ray);
	return t;
}

Vector3D Rectangle::getNormal(const Point3D& ip) const
{
	return normal;
}

void Rectangle::setMaterial(const Material* mat)
{
	material = mat;
}

const Material* Rectangle::getMaterial(const Point3D& hitPoint) const
{
	return material;
}

Sample2D Rectangle::getUV(const Point3D& hitPoint) const
{
	Vector3D pointDir = hitPoint - position;
	float u = DotProduct(right, pointDir) / width;
	float v = DotProduct(up, pointDir) / height;
	return { u, v };
}