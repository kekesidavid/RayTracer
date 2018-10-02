#include "Pixel.h"
#include "Color.h"

Pixel::Pixel() 
	: incomingColor(Color(0, 0, 0)), numOfSamples(0)
{
}

void Pixel::addColor(const Color& color)
{
	incomingColor = incomingColor + color;
	numOfSamples++;
}

Color Pixel::getAverageColor() const
{
	if (numOfSamples == 0) return incomingColor;
	else return incomingColor * (1.0f / numOfSamples);
}