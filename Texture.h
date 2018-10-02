#pragma once
#include "Picture.h"
#include "Color.h"

class Texture
{
private:

	Picture picture;

public:

	Texture();
	Texture(const char*);

	void loadPictureFromFile(const char*);
	Color getColor(float, float) const;
};