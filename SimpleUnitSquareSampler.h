#pragma once
#include "UnitSquareSampler.h"
#include "Sample2D.h"

class SimpleUnitSquareSampler : public UnitSquareSampler
{
private:

public:

	SimpleUnitSquareSampler();

	Sample2D getSample() const;

};