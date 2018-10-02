#include <time.h>
#include <iostream>
#include "UnitSquareSampler.h"
#include "JitteredUnitSquareSampler.h"
#include "Sample2D.h"

JitteredUnitSquareSampler::JitteredUnitSquareSampler()
{
	srand(time(NULL));
}

Sample2D JitteredUnitSquareSampler::getSample() const
{	
	float u = (float)rand() / RAND_MAX;
	float v = (float)rand() / RAND_MAX;
	return { 0.5f, 0.5f };
}