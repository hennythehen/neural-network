#pragma once
class Neuron
{
private:
	double output;
	double bias;
public:
	virtual double internalFunc(double input) = 0;
	double getOutput();
	double getBias();
	void setBias(double);
	Neuron();
	~Neuron();
};

