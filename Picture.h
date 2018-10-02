#pragma once
#include "Pixel.h"
#include "Color.h"

class Picture
{
private:

	int width;
	int height;
	Pixel* pixels;

public:

	Picture();
	Picture(int, int);

	void addPixelColor(int, int, Color);
	Color getPixelColor(int, int) const;
	int getWidth() const;
	int getHeight() const;
	void printToFile(const char*) const;
	void readFromFile(const char*);
	void clearPixels();
};