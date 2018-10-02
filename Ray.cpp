#include <iostream>
#include "Ray.h"
#include "Point3D.h"
#include "Vector3D.h"

Ray::Ray()
{
}

Ray::Ray(const Ray& ray) 
	: origin(ray.origin), direction(ray.direction)
{
	direction.normalize();
}

Ray::Ray(const Point3D& origin, Vector3D& direction) 
	: origin(origin), direction(direction)
{
	direction.normalize();
}

Ray::Ray(const Point3D& origin, const Point3D& dir)
	: origin(origin), direction(dir - origin)
{
	direction.normalize();
}

Ray& Ray::operator=(const Ray& ray)
{
	origin = ray.origin;
	direction = ray.direction;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Ray& ray)
{
	os << "Ray:: origin=" << ray.origin << " direction=" << ray.direction;
	return os;
}

Point3D Ray::getOrigin() const
{
	return origin;
}

Vector3D Ray::getDirection() const
{
	return direction;
}

Point3D Ray::getPointAt(float t) const
{
	return origin + (direction * t);
}

Ray Ray::getReflectedRay(const Point3D& p, const Vector3D& normal) const
{
	float cosAlpha = -(DotProduct(direction, normal));
	Vector3D reflectionDir = direction + normal * cosAlpha * 2;
	return Ray(p, reflectionDir);
}

Ray Ray::getRefractedRay(const Point3D& p, const Vector3D& normal, float ior) const
{
	float n = 1 / ior;
	Vector3D norm = normal;

	//if alpha is negative you are inside the object
	float cosAlpha = -(DotProduct(direction, norm));
	if (cosAlpha < 0)
	{
		norm = norm * (-1);
		cosAlpha = -cosAlpha;
		n = 1 / n;
	}

	//if discriminant is negative ray will be reflected
	float discr = 1 - (1 - cosAlpha * cosAlpha) * (n * n);
	if (discr < 0)
	{
		return getReflectedRay(p, norm);
	}

	Vector3D refractionDir = (direction * n) + norm * (cosAlpha * n - sqrt(discr));
	return Ray(p, refractionDir);
}



