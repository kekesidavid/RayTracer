#include "Tracer.h"
#include "RecursiveRayTracer.h"
#include "AppConstants.h"
#include "Colors.h"
#include "Material.h"
#include "Light.h"

RecursiveRayTracer::RecursiveRayTracer()
{
}

Color RecursiveRayTracer::traceSingleRay(const Ray& ray) const
{
	return traceRayRecursively(ray, 0);
}

Color RecursiveRayTracer::traceRayRecursively(const Ray& ray, int depth) const
{
	Hit hit = scene->getNearestIntersect(ray);
	if (hitsNothing(hit)) return colors::BLACK;
	if(maxDepthReached(depth)) return colors::CYAN;

	Color outColor(0, 0, 0);
	if (hitsDiffuse(hit) || hitsTextured(hit)) outColor += shadeDiffuse(hit);
	if (hitsReflective(hit)) outColor += traceReflectedRay(ray, hit, depth);
	if (hitsRefractive(hit)) outColor += traceRefractedRay(ray, hit, depth);

	return outColor;
}

Color RecursiveRayTracer::shadeDiffuse(const Hit& hit) const
{
	Color outColor(0, 0, 0);
	std::vector<const Light*> lights = scene->getLights();
	for (const Light* light : lights)
	{
		outColor += shadeHitpointWithSingleLight(hit, light);
	}
	return outColor;
}

Color RecursiveRayTracer::traceReflectedRay(const Ray& ray, const Hit& hit, int depth) const
{
	
	const Material* material = hit.getMaterial();
	Color frensel = Frensel(hit.getInDir(), hit.getNormal(), material->getColor());
	Ray reflectedRay = ray.getReflectedRay(hit.getHitPoint(), hit.getNormal());

	return traceRayRecursively(reflectedRay, depth + 1) * frensel;
}

Color RecursiveRayTracer::traceRefractedRay(const Ray& ray, const Hit& hit, int depth) const
{
	const Material* material = hit.getMaterial();
	Color frensel = Frensel(hit.getInDir(), hit.getNormal(), material->getColor());
	Ray refractedRay = ray.getRefractedRay(hit.getHitPoint(), hit.getNormal(), material->getIor());

	return traceRayRecursively(refractedRay, depth + 1) * (colors::WHITE - frensel);
}

Color RecursiveRayTracer::Frensel(const Vector3D& viewDir, const Vector3D& normal, const Color& color) const
{
	float cosAlpha = fabs(DotProduct(normal, viewDir));
	return color + (colors::WHITE - color) * pow((1 - cosAlpha), 5);
}

Color RecursiveRayTracer::shadeHitpointWithSingleLight(const Hit& hit, const Light* light) const
{
	Point3D hitPoint = hit.getHitPoint();
	Point3D lightPos = light->getPosition();
	Ray shadowRay = Ray(hitPoint, lightPos);
	float lightDist = hitPoint.getDistanceTo(lightPos);
	
	if (pointIsShadowed(shadowRay, lightDist))
	{
		return colors::SHADOW_COLOR;
	}
	else
	{
		Vector3D lightDir = shadowRay.getDirection();
		float lightIntensity = light->getIntensityInPoint(hitPoint);
		Sample2D uvPoint = hit.getHitObject()->getUV(hitPoint);
		Color materialColor = hit.getMaterial()->getColor(uvPoint.u, uvPoint.v);
		float lambertian = CosTheta(hit.getNormal(), lightDir);

		return light->getColor() * materialColor * lambertian * lightIntensity;
	}
}

bool RecursiveRayTracer::pointIsShadowed(const Ray& shadowRay, float lightDist) const
{
	float obstacleDist = scene->distanceOfNearestIntersect(shadowRay);
	return obstacleDist < lightDist;
}

bool RecursiveRayTracer::hitsNothing(const Hit& hit) const
{
	return hit.getHitObject() == nullptr;
}

bool RecursiveRayTracer::hitsDiffuse(const Hit& hit) const
{
	return hit.getMaterial()->getType() == DIFFUSE;
}

bool RecursiveRayTracer::hitsTextured(const Hit& hit) const
{
	return hit.getMaterial()->getType() == TEXTURED;
}

bool RecursiveRayTracer::hitsReflective(const Hit& hit) const
{
	return hit.getMaterial()->getType() == REFLECTIVE;
}

bool RecursiveRayTracer::hitsRefractive(const Hit& hit) const
{
	return hit.getMaterial()->getType() == REFRACTIVE;
}

bool RecursiveRayTracer::maxDepthReached(int bounces) const
{
	return !(bounces < MAX_DEPTH);
}