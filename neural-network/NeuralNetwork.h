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
	void applyWeightDelta(std::vector<double> origOutput, double delta_j, int destLayerIndex);
public:
	int getNumLayers();
	void dumpWeights();
	void train(std::vector<double> input, std::vector<double> expectedOutput);
	NeuralNetwork(int, int* const);
};
