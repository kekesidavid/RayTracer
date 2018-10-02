#include "RefractiveMaterial.h"
#include "Color.h"
#include "Vector3D.h"

RefractiveMaterial::RefractiveMaterial()
{
	materialType = REFRACTIVE;
	ior = 1.0f;
}

RefractiveMaterial::RefractiveMaterial(const Color& c, float iorVal)
{
	materialType = REFRACTIVE;
	color = c;
	ior = iorVal;
}

void RefractiveMaterial::setColor(const Color& c)
{
	color = c;
}

Color RefractiveMaterial::getColor() const
{
	return color;
}

material_type RefractiveMaterial::getType() const
{
	return materialType;
}

void RefractiveMaterial::setIor(float iorVal)
{
	ior = iorVal;
}

float RefractiveMaterial::getIor() const
{
	return ior;
}