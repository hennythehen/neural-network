#pragma once
#include "Neuron.h"
#include <cmath>

class SigmoidNeuron
{
private:
	
public:
	static double internalFunc(double input)
	{
		return 1 / (1 + exp((-1) * input));
	}
	SigmoidNeuron();
	~SigmoidNeuron();
};

