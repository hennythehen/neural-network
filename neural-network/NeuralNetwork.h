#pragma once
#include "AdjacencyList.h"
#include "SigmoidNeuron.h"

class NeuralNetwork
{
private:
	AdjacencyList<SigmoidNeuron>* adjList;
	//Layer<Neuron> inputLayer;
	//Layer<Neuron> outputLayer;
	
public:
	//void train(std::vector<double> input, std::vector<double> expectedOutput);
	NeuralNetwork(int, int* const);
};
