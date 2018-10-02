#include <iostream>
#include <fstream>
#include "Picture.h"
#include "Pixel.h"
#include "Color.h"

Picture::Picture() 
	: width(0), height(0)
{
}

Picture::Picture(int width, int height) 
	: width(width), height(height)
{
	pixels = new Pixel[width * height];
}

void Picture::addPixelColor(int w, int h, Color color)
{
	pixels[width * h + w].addColor(color);
}

Color Picture::getPixelColor(int w, int h) const
{
	return pixels[width * h + w].getAverageColor();
}

int Picture::getWidth() const
{
	return width;
}

int Picture::getHeight() const
{
	return height;
}

void Picture::printToFile(const char* fileName) const
{
	std::ofstream pic;
	pic.open(fileName);
	pic << "P3" << std::endl << width << " " << height << " 255" << std::endl;

	int size = width * height;
	for (int i = 0; i < size; i++)
	{
		pic << pixels[i].getAverageColor();
	}

	pic.close();
}

void Picture::readFromFile(const char* fileName)
{
	std::ifstream imgFile(fileName, std::ios::binary);

	char c;
	imgFile >> c;
	imgFile >> c;

	int widthVal, heightVal, maxSize;
	imgFile >> widthVal;
	imgFile >> heightVal;
	imgFile >> maxSize;

	imgFile.get(c);

	width = widthVal;
	height = heightVal;
	int picSize = width * height;
	pixels = new Pixel[picSize];
	
	char val;
	Color color;
	for (int i = 0; i < picSize; i++)
	{
		imgFile >> color;
		pixels[i].addColor(color);
	}
}

void Picture::clearPixels()
{
	delete[] pixels;
}