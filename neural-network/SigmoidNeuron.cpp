#include "SigmoidNeuron.h"
#include <math.h>


SigmoidNeuron::SigmoidNeuron()
{
}

double SigmoidNeuron::internalFunc(double input)
{
	return 1 / (1 + exp((-1) * input));
}

SigmoidNeuron::~SigmoidNeuron()
{
}
