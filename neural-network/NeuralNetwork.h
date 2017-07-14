#pragma once
#include "AdjacencyList.h"
#include "SigmoidNeuron.h"

class NeuralNetwork
{
private:
	AdjacencyList<SigmoidNeuron>* adjList;
	std::vector<std::vector<int>*> neuronLayers;
	std::vector<std::vector<double>> layerOutputs;

	std::vector<double> propagate(std::vector<double> input,
		int origLayer,
		int destLayer,
		std::vector<std::vector<double>> &outputCache);
	std::vector<double> backPropagate(double error, int currLayer, int backLayer);
public:
	int getNumLayers();

	void train(std::vector<double> input, std::vector<double> expectedOutput);
	NeuralNetwork(int, int* const);
};
