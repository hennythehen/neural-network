#include "NeuralNetwork.h"
#include "AdjacencyList.h"
#include "../math-library/vmath.h"

NeuralNetwork::NeuralNetwork(int layerCount, int* const neuronsInLayers)
{
	this->adjList = new AdjacencyList<SigmoidNeuron>();
	for (int i = 0; i < layerCount; i++) {
		int numNeurons = neuronsInLayers[i];
		std::vector<int>* neuronIndices = new std::vector<int>();
		for (int j = 0; j < numNeurons; j++) {
			SigmoidNeuron* neuron = new SigmoidNeuron();
			neuronIndices->push_back(this->adjList->insert(neuron));
		}
		this->neuronLayers.push_back(neuronIndices);
	}

	for (int i = 0; i < this->neuronLayers.size() - 2; i++) {
		this->adjList->connect(this->neuronLayers.at(i), this->neuronLayers.at(i + 1));
	}
}

void NeuralNetwork::train(std::vector<double> input, std::vector<double> expectedOutput)
{
	std::vector<std::vector<double>> layerOutputs;
	layerOutputs.push_back(input);
	std::vector<double> output = propagate(input, 0, 1, layerOutputs);
	double error = vectorNorm(vectorSubtract(output, expectedOutput));
	
}

std::vector<double> NeuralNetwork::propagate(
	std::vector<double> input,
	int origLayerIndex,
	int destLayerIndex,
	std::vector<std::vector<double>> &outputCache)
{
	std::vector<int>* destNodeIndices = this->neuronLayers.at(destLayerIndex);
	std::vector<double> output;
	for (int i = 0; i < destNodeIndices->size(); i++) {
		std::vector<double> weights = this->adjList->getBackEdgeWeights(destNodeIndices->at(i));
		double result = dotProduct(input, weights);
		output.push_back(SigmoidNeuron::internalFunc(result));
	}

	outputCache.push_back(output);
	//check if the output layer has been reached
	if (destLayerIndex == this->getNumLayers() - 1) {
		return output;
	}
	else {
		return this->propagate(output, destLayerIndex, destLayerIndex + 1);
	}
}

int NeuralNetwork::getNumLayers()
{
	return this->neuronLayers.size();
}