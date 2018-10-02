#include "Texture.h"
#include "Picture.h"
#include "Color.h"

Texture::Texture()
{
}

Texture::Texture(const char* fileName)
{
	loadPictureFromFile(fileName);
}

void Texture::loadPictureFromFile(const char* fileName)
{
	picture.readFromFile(fileName);
}

Color Texture::getColor(float u, float v) const
{
	int w = (int)(picture.getWidth() * u);
	int h = (int)(picture.getHeight() * v);
	return picture.getPixelColor(w, h);
}