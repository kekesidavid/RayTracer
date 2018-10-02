#pragma once
#include "Ray.h"
#include "Color.h"

class Bounce
{

private:

	enum Type {DIFFUSE, REFLECTIVE, REFRACTIVE};
	Type type;
	Ray redirectedRay;
	Color color;

public:

	Bounce();

	void setDiffuse();
	void setReflective();
	void setRefractive();
	void setRedirectedRay(const Ray&);
	void setColor(const Color&);

	bool isDiffuse() const;
	bool isReflective() const;
	bool isRefractive() const;


	Ray getRedirectedRay() const;
	Color getColor() const;

};