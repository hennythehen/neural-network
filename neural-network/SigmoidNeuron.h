#pragma once
#include "Neuron.h"
class SigmoidNeuron
{
private:
	double internalFunc(double input);
public:
	SigmoidNeuron();
	~SigmoidNeuron();
};

