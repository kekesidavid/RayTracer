#include "DiffuseMaterial.h"
#include "Color.h"
#include "Vector3D.h"

DiffuseMaterial::DiffuseMaterial()
{
	materialType = DIFFUSE;
	ior = 1.0f;
}

DiffuseMaterial::DiffuseMaterial(const Color& c)
{
	materialType = DIFFUSE;
	color = c;
	ior = 1.0f;
}

void DiffuseMaterial::setColor(const Color& c)
{
	color = c;
}

Color DiffuseMaterial::getColor() const 
{
	return color;
}

material_type DiffuseMaterial::getType() const
{
	return materialType;
}

float DiffuseMaterial::getIor() const
{
	return ior;
}