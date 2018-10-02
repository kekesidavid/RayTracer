#include <iostream>
#include <fstream>
#include "Color.h"

Color::Color()
{
}

Color::Color(const Color& c) 
	: r(c.r), g(c.g), b(c.b)
{
}

Color::Color(float r, float g, float b) 
	: r(r), g(g), b(b)
{
}

Color& Color::operator=(const Color& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	return *this;
}

Color Color::operator+(const Color& c) const
{
	return Color(r + c.r, g + c.g, b + c.b);
}

Color& Color::operator+=(const Color& c)
{
	r += c.r;
	g += c.g;
	b += c.b;
	return *this;
}

Color Color::operator-(const Color& c) const
{
	return Color(r - c.r, g - c.g, b - c.b);
}

Color Color::operator*(float m) const
{
	return Color(r * m, g * m, b * m);
}

Color Color::operator*(const Color& c) const
{
	return Color(r * c.r, g * c.g, b * c.b);
}

int Color::R255() const
{
	return floatToInt255(r);
}

int Color::G255() const
{
	return floatToInt255(g);
}

int Color::B255() const
{
	return floatToInt255(b);
}

int Color::floatToInt255(float f) const
{
	int val = (int)(f * 255);
	if (val > 255) val = 255;
	return val;
}

std::ostream& operator<<(std::ostream& os, const Color& c)
{
	os << c.R255() << " " << c.G255() << " " << c.B255() << " ";
	return os;
}

std::ifstream& operator>>(std::ifstream& ifs, Color& c)
{
	char r, g, b;
	ifs.get(r);
	ifs.get(g);
	ifs.get(b);

	float rf = (unsigned char)(r) / 255.0f;
	float gf = (unsigned char)(g) / 255.0f;
	float bf = (unsigned char)(b) / 255.0f;

	c = Color(rf, gf, bf);
	return ifs;
}