#include "Hit.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "GeometricObject.h"

Hit::Hit()
{
}

Hit::Hit(const Hit& hit) 
	: hitObject(hit.hitObject), hitPoint(hit.hitPoint), inDir(hit.inDir)
{
}

Hit::Hit(const GeometricObject* object, const Point3D& ip, const Vector3D& viewDir)
	: hitObject(object), hitPoint(ip), inDir(viewDir)
{
}

Hit::Hit(const GeometricObject* object, const Ray& ray, float dist) 
	: hitObject(object)
{
	hitPoint = ray.getPointAt(dist);
	inDir = ray.getDirection();
}

const GeometricObject* Hit::getHitObject() const
{
	return hitObject;
}

Point3D Hit::getHitPoint() const
{
	return hitPoint;
}

Vector3D Hit::getNormal() const
{
	return hitObject->getNormal(hitPoint);
}

Vector3D Hit::getInDir() const
{
	return inDir;
}

const Material* Hit::getMaterial() const
{
	return hitObject->getMaterial(hitPoint);
}