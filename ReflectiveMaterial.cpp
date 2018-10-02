#include "ReflectiveMaterial.h"
#include "Color.h"
#include "Vector3D.h"

ReflectiveMaterial::ReflectiveMaterial()
{
	materialType = REFLECTIVE;
	ior = 1.0f;
}

ReflectiveMaterial::ReflectiveMaterial(const Color& c)
{
	materialType = REFLECTIVE;
	color = c;
	ior = 1.0f;
}

void ReflectiveMaterial::setColor(const Color& c)
{
	color = c;
}

Color ReflectiveMaterial::getColor() const
{
	return color;
}

material_type ReflectiveMaterial::getType() const
{
	return materialType;
}

float ReflectiveMaterial::getIor() const
{
	return ior;
}