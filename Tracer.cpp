#include "Tracer.h"
#include "Scene.h"
#include "Hit.h"
#include "Ray.h"
#include "Color.h"

Tracer::Tracer()
{
}

void Tracer::setScene(const Scene& sc)
{
	scene = &sc;
}