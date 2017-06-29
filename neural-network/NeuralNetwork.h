#pragma once
#include <vector>
#include "AdjacencyList.h"
#include "SigmoidNeuron.h"
#include "Layer.h"

class NeuralNetwork
{
protected:
	AdjacencyList<Neuron> adjList;
	//Layer<Neuron> inputLayer;
	//Layer<Neuron> outputLayer;
	
public:
	void train(std::vector<double> input, std::vector<double> expectedOutput);
	NeuralNetwork(int layerCount, int neuronsInLayer[]);
	~NeuralNetwork();
};
