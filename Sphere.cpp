#include "Sphere.h"
#include "GeometricObject.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Ray.h"
#include "AppConstants.h"

Sphere::Sphere()
{
}

Sphere::Sphere(const Sphere& s) 
	: center(s.center), radius(s.radius)
{
}

Sphere::Sphere(const Point3D& center, float radius) 
	: center(center), radius(radius)
{
}

float Sphere::intersect(const Ray& ray) const
{
	Vector3D rayDir = ray.getDirection();
	rayDir.normalize();
	Vector3D rayOrigin = ray.getOrigin() - Point3D(0, 0, 0);

	Vector3D sphereCenter = center - Point3D(0, 0, 0);
	Vector3D centerToOrigin = rayOrigin - sphereCenter;

	float a = DotProduct(rayDir, rayDir);
	float b = DotProduct(rayDir, centerToOrigin) * 2;
	float c = DotProduct(sphereCenter, sphereCenter) + DotProduct(rayOrigin, rayOrigin) - 
		2 * DotProduct(sphereCenter, rayOrigin) - (radius * radius);

	float discriminant = b * b - 4 * a*c;
	if (discriminant < 0)
	{
		return appconst::MISS;
	}
	else
	{
		float t = (-1.0f*b - sqrt(discriminant)) / (2.0f * a);
		return t;
	}
}

Vector3D Sphere::getNormal(const Point3D& p) const
{
	Vector3D normal = p - center;
	normal.normalize();
	return normal;
}

void Sphere::setMaterial(const Material* mat)
{
	material = mat;
}

const Material* Sphere::getMaterial(const Point3D&) const
{
	return material;
}

Sample2D Sphere::getUV(const Point3D& hitPoint) const
{
	return { 0, 0 };
}