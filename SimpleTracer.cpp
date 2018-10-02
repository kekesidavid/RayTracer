#include "Tracer.h"
#include "SimpleTracer.h"
#include "AppConstants.h"
#include "Colors.h"

SimpleTracer::SimpleTracer()
{
}

Color SimpleTracer::traceSingleRay(const Ray& ray) const
{
	Hit hit = scene->getNearestIntersect(ray);
	if (hitsNothing(hit)) return colors::BG_COLOR;
	return outColor(hit);
}

Color SimpleTracer::outColor(const Hit& hit) const
{
	return hit.getMaterial()->getColor();
}

bool SimpleTracer::hitsNothing(const Hit& hit) const
{
	return hit.getHitObject() == nullptr;
}