#pragma once
#include "AdjacencyList.h"
#include "SigmoidNeuron.h"

class NeuralNetwork
{
private:
	AdjacencyList<SigmoidNeuron>* adjList;
	std::vector<std::vector<int>*> neuronLayers;
	std::vector<std::vector<double>> layerOutputCache;
	double trainingSpeedFactor;

	std::vector<double> propagate(std::vector<double> input,
		std::vector<double> expectedOutput,
		int origLayer,
		int destLayer);
	std::vector<double> backPropagate(std::vector<double> error,
		int currLayer, 
		int backLayer);
	void applyWeightDelta(std::vector<double> origOutput, double delta_j, int destLayerIndex);
public:
	int getNumLayers();

	void train(std::vector<double> input, std::vector<double> expectedOutput);
	NeuralNetwork(int, int* const);
};
