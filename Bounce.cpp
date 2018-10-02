#include "Ray.h"
#include "Color.h"
#include "Bounce.h"

Bounce::Bounce() 
	: type(DIFFUSE)
{
}

void Bounce::setDiffuse()
{
	type = DIFFUSE;
}

void Bounce::setReflective()
{
	type = REFLECTIVE;
}

void Bounce::setRefractive()
{
	type = REFRACTIVE;
}

void Bounce::setRedirectedRay(const Ray& ray)
{
	redirectedRay = ray;
}

void Bounce::setColor(const Color& c)
{
	color = c;
}

bool Bounce::isDiffuse() const
{
	return type == DIFFUSE;
}

bool Bounce::isReflective() const
{
	return type == DIFFUSE;
}

bool Bounce::isRefractive() const
{
	return type == DIFFUSE;
}

Ray Bounce::getRedirectedRay() const
{
	return redirectedRay;
}

Color Bounce::getColor() const
{
	return color;
}