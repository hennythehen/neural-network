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
	std::vector<double> inputLayerError = propagate(input, expectedOutput, 0, 1);
}

std::vector<double> NeuralNetwork::propagate(
	std::vector<double> input,
	std::vector<double> expectedOutput,
	int origLayerIndex,
	int destLayerIndex)
{
	/*
	Begins a recursive forward propagation from input layer to output layer.
	Each stack frame will eventually be used for back propagation.
	*/
	std::vector<int>* destNodeIndices = this->neuronLayers.at(destLayerIndex);
	std::vector<double> output;
	for (int i = 0; i < destNodeIndices->size(); i++) {
		std::vector<double> weights = this->adjList->getBackEdgeWeights(destNodeIndices->at(i));
		double result = dotProduct(input, weights);
		output.push_back(SigmoidNeuron::internalFunc(result));
	}

	/*
	The peak of the recursion stack will be the last (output) layer of the network.
	*/

	if (destLayerIndex == this->getNumLayers() - 1) {
		std::vector<double> delta_f = vectorSubtract(output, expectedOutput);
		for (int k = 0; k < delta_f.size(); k++) {
			delta_f.at(k) *= (output.at(k) * (1 - output.at(k)));
			applyWeightDelta(input, delta_f.at(k), destLayerIndex);
		}
		return delta_f;
	}
	

	std::vector<double> delta_l = this->propagate(output, expectedOutput, destLayerIndex, destLayerIndex + 1);
	
	/*
	The error coming from the forward layer is known.
	Unwinding the stack accesses each layer and its input in reverse succession.
	With the layer's input and forward error known, weight deltas can be applied
	*/
	std::vector<int>* origNodeIndices = this->neuronLayers.at(origLayerIndex);
	std::vector<double> delta_j;
	
	for (int i = 0; i < origNodeIndices->size(); i++) {
		double delta_j_i = dotProduct(this->adjList->getForwardEdgeWeights(origNodeIndices->at(i)), delta_l) * input.at(i) * (1 - input.at(i));
		delta_j.push_back(delta_j_i);
		applyWeightDelta(input, delta_j_i, destLayerIndex);
	}
}

void NeuralNetwork::applyWeightDelta(std::vector<double> origOutput, double delta_j, int destNodeIndex)
{
	std::vector<double> backWeights = this->adjList->getBackEdgeWeights(destNodeIndex);
	for (int i = 0; i < backWeights.size(); i++) {
		double weightDelta_i = this->trainingSpeedFactor * origOutput.at(i) * delta_j * (-1);
		backWeights.at(i) += weightDelta_i;
	}
}

std::vector<double> NeuralNetwork::backPropagate(std::vector<double> error,
	int currLayer,
	int backLayer)
{
	
}

int NeuralNetwork::getNumLayers()
{
	return this->neuronLayers.size();
}