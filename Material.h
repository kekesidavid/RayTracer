#pragma once
#include "Color.h"
#include "Vector3D.h"

enum material_type
{
	DIFFUSE,
	REFLECTIVE,
	REFRACTIVE,
	TEXTURED
};

class Material
{
protected:

	Color color;
	float ior;
	material_type materialType;

public:

	virtual void setColor(const Color&) = 0;
	virtual Color getColor() const = 0;
	virtual Color getColor(float, float) const { return color; }
	virtual material_type getType() const = 0;
	virtual float getIor() const = 0;
};