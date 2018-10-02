#pragma once
#include "Color.h"

class Pixel
{
private:
	Color incomingColor;
	int numOfSamples;

public:

	Pixel();

	void addColor(const Color&);
	Color getAverageColor() const;
};