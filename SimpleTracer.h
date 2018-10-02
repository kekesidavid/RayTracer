#pragma once
#include "Color.h"
#include "Tracer.h"

class SimpleTracer : public Tracer
{
private:

public:

	SimpleTracer();

	Color traceSingleRay(const Ray& ray) const;
	Color outColor(const Hit&) const;
	bool hitsNothing(const Hit&) const;
};