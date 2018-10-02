#pragma once
#include "Color.h"
#include "Point3D.h"

class Light
{
private:

	Point3D position;
	Color color;
	float intensity;

public:
	Light();
	virtual ~Light();

	void setPosition(const Point3D&);
	void setColor(const Color&);
	void setIntensity(const float);

	Point3D getPosition() const;
	Color getColor() const;
	float getIntensityInPoint(const Point3D&) const;
};