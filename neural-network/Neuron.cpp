#pragma once
#include "Neuron.h"

double Neuron::getBias()
{
	return this->bias;
}

void Neuron::setBias(double bias)
{
	this->bias = bias;
	return;
}

double Neuron::getOutput()
{
	return this->output;
}