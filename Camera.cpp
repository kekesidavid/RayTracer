#include <iostream>
#include "Camera.h"
#include "Ray.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "UnitSquareSampler.h"
#include "Sample2D.h"

Camera::Camera()
{
}

Camera::Camera(int width, int height) 
	: width(width), height(height), position(Point3D(0, 0, 0)), direction(Vector3D(0, 1, 0)), length(1000.0f)
{
	updateUnitDirections();
}

void Camera::updateUnitDirections()
{
	//direction is parallel with axis z
	if (DotProduct(Vector3D(0, 1, 0), direction) == 0)
	{
		right = CrossProduct(direction, Vector3D(0, 1, 0));
	}
	else 
	{
		right = CrossProduct(direction, Vector3D(0, 0, 1));
	}
	right.normalize();

	up = CrossProduct(right, direction);
	up.normalize();

	left = right * (-1.0f);
	down = up * (-1.0f);

	direction.normalize();
	centerOfPicture = position + (direction * length);
	upLeftCorner = centerOfPicture + (left * (width / 2)) + (up * (height / 2));
}

void Camera::setPosition(const Point3D& p)
{
	position = p;
}

void Camera::setDirection(const Vector3D& dir)
{
	direction = dir;
	updateUnitDirections();
}

void Camera::setLength(float len)
{
	length = len;
	updateUnitDirections();
}

void Camera::setSampler(const UnitSquareSampler* uss)
{
	sampler = uss;
	updateUnitDirections();
}

Point3D Camera::getSamplePointOnPicturePlane(int w, int h) const
{
	Sample2D sample2D = sampler->getSample();
	Point3D samplePoint = upLeftCorner + (right * (w + sample2D.u)) + (down * (h + sample2D.v));
	return samplePoint;
}

Ray Camera::getSampleRayThroughPixel(int w, int h) const
{
	Point3D samplePoint = getSamplePointOnPicturePlane(w, h);
	return Ray(position, samplePoint);
}