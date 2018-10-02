#pragma once
#include "Material.h"
#include "Color.h"
#include "Vector3D.h"

class RefractiveMaterial : public Material
{
private:

public:

	RefractiveMaterial();
	RefractiveMaterial(const Color&, float);

	void setColor(const Color&);
	Color getColor() const;
	material_type getType() const;
	void setIor(float);
	float getIor() const;
};
