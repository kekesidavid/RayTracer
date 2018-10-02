#include "Light.h"
#include "Color.h"
#include "Colors.h"
#include "Point3D.h"

Light::Light()
{
	color = colors::WHITE;
	intensity = 1000.0f;
}

Light::~Light()
{
}

void Light::setPosition(const Point3D& p)
{
	position = p;
}

void Light::setColor(const Color& c)
{
	color = c;
}

void Light::setIntensity(float i)
{
	intensity = i;
}

Point3D Light::getPosition() const
{
	return position;
}

Color Light::getColor() const
{
	return color;
}

float Light::getIntensityInPoint(const Point3D& p) const 
{
	float dist = position.getDistanceTo(p);
	return intensity / (dist * dist);
}