#pragma once
#include "Material.h"
#include "Color.h"
#include "Vector3D.h"

class ReflectiveMaterial : public Material
{
private:

public:

	ReflectiveMaterial();
	ReflectiveMaterial(const Color&);

	void setColor(const Color&);
	Color getColor() const;
	material_type getType() const;
	float getIor() const;
};
