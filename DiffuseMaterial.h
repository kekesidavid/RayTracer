#pragma once
#include "Material.h"
#include "Color.h"
#include "Vector3D.h"

class DiffuseMaterial : public Material
{
private:

public:

	DiffuseMaterial();
	DiffuseMaterial(const Color&);

	void setColor(const Color&);
	Color getColor() const;
	material_type getType() const;
	float getIor() const;
};