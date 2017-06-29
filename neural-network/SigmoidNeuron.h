#pragma once
#include "Neuron.h"
class SigmoidNeuron : public Neuron
{
private:
	double internalFunc(double input);
public:
	SigmoidNeuron();
	~SigmoidNeuron();
};

