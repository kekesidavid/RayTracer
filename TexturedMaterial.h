#pragma once
#include "Material.h"
#include "Texture.h"

class TexturedMaterial : public Material
{
private:

	const Texture* texture;

public:

	TexturedMaterial();
	TexturedMaterial(const Texture*);

	void setTexture(const Texture*);
	void setColor(const Color&);
	Color getColor() const;
	Color getColor(float, float) const;
	material_type getType() const;
	float getIor() const;
};