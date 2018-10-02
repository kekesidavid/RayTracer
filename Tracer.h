#pragma once
#include "Scene.h"
#include "Hit.h"
#include "Ray.h"
#include "Color.h"

class Tracer
{
protected:

	const Scene* scene;

public:

	Tracer();

	virtual Color traceSingleRay(const Ray& ray) const = 0;
	void setScene(const Scene&);
};