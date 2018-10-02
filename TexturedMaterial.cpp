#include "TexturedMaterial.h"
#include "Color.h"
#include "Vector3D.h"
#include "Colors.h"

TexturedMaterial::TexturedMaterial()
{
	materialType = DIFFUSE;
	color = colors::WHITE;
	ior = 1.0f;
}

TexturedMaterial::TexturedMaterial(const Texture* tex)
{
	materialType = DIFFUSE;
	color = colors::WHITE;
	texture = tex;
	ior = 1.0f;
}

void TexturedMaterial::setTexture(const Texture* tex)
{
	texture = tex;
}

void TexturedMaterial::setColor(const Color& c)
{
	color = c;
}

Color TexturedMaterial::getColor() const
{
	return color;
}

Color TexturedMaterial::getColor(float u, float v) const
{
	return texture->getColor(u, v);
}

material_type TexturedMaterial::getType() const
{
	return materialType;
}

float TexturedMaterial::getIor() const
{
	return ior;
}