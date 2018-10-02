#include "UnitSquareSampler.h"
#include "SimpleUnitSquareSampler.h"
#include "Sample2D.h"

SimpleUnitSquareSampler::SimpleUnitSquareSampler()
{
}

Sample2D SimpleUnitSquareSampler::getSample() const
{
	return { 0.5f, 0.5f };
}