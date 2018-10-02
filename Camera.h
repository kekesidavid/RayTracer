#pragma once
#include "Pixel.h"
#include "Ray.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "UnitSquareSampler.h"

class Camera
{
private:

	int width;
	int height;

	Point3D position;
	Vector3D direction;
	Vector3D up;
	Vector3D down;
	Vector3D right;
	Vector3D left;

	float length;
	Point3D centerOfPicture;
	Point3D upLeftCorner;
	const UnitSquareSampler* sampler;

	Camera();
	void updateUnitDirections();

public:

	Camera(int, int);

	void setPosition(const Point3D&);
	void setDirection(const Vector3D&);
	void setLength(float);
	void setSampler(const UnitSquareSampler*);

	Point3D getSamplePointOnPicturePlane(int, int) const;
	Ray getSampleRayThroughPixel(int, int) const;
};