#pragma once
#include <iostream>

class Color
{
private:

	float r, g, b;
	int R255() const;
	int G255() const;
	int B255() const;
	int floatToInt255(float) const;

public:

	Color();
	Color(const Color &);
	Color(float, float, float);

	Color& operator=(const Color&);
	Color operator+(const Color&) const;
	Color& operator +=(const Color&);
	Color operator-(const Color&) const;
	Color operator*(float) const;
	Color operator*(const Color&) const;

	friend std::ostream& operator<<(std::ostream&, const Color&);
	friend std::ifstream& operator>>(std::ifstream&, Color&);
};