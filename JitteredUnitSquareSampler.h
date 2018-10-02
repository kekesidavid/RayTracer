#pragma once
#include "UnitSquareSampler.h"
#include "Sample2D.h"

class JitteredUnitSquareSampler : public UnitSquareSampler
{
private:

public:

	JitteredUnitSquareSampler();

	Sample2D getSample() const;

};
