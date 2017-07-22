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

	static double internalDerivFunc(double input)
	{
		return exp(input) / pow((exp(input) + 1), 2);
	}

	SigmoidNeuron();
	~SigmoidNeuron();
};

