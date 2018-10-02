#pragma once
#include "Color.h"
#include "Tracer.h"

class RecursiveRayTracer : public Tracer
{
private:

	const int MAX_DEPTH = 4;

public:

	RecursiveRayTracer();

	Color traceSingleRay(const Ray&) const;
	Color traceRayRecursively(const Ray&, int) const;

	Color shadeDiffuse(const Hit&) const;
	Color traceReflectedRay(const Ray&, const Hit&, int) const;
	Color traceRefractedRay(const Ray&, const Hit&, int) const;
	Color Frensel(const Vector3D&, const Vector3D&, const Color&) const;

	Color shadeHitpointWithSingleLight(const Hit&, const Light*) const;
	bool pointIsShadowed(const Ray&, float) const;

	bool hitsNothing(const Hit&) const;
	bool hitsDiffuse(const Hit&) const;
	bool hitsTextured(const Hit&) const;
	bool hitsReflective(const Hit&) const;
	bool hitsRefractive(const Hit&) const;
	bool maxDepthReached(int) const;
};
