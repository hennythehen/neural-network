#include "NeuralNetwork.h"
#include "AdjacencyList.h"
#include "../math-library/vmath.h"
#include <iostream>

void NeuralNetwork::dumpWeights()
{
    std::vector<AdjacencyListNode<SigmoidNeuron>*> nodes = this->adjList->getNodes();
    for(int i = 0; i < nodes.size(); i++) {
        std::vector<double> weights = this->adjList->getForwardEdgeWeights(i);
        printf("Node %d \n", i);
        for (int j = 0; j < weights.size(); j++) {
            printf("%f\n", weights.at(j));
        }
    }
}

NeuralNetwork::NeuralNetwork(int layerCount, int* const neuronsInLayers)
{
    this->trainingSpeedFactor = 2;
	this->adjList = new AdjacencyList<SigmoidNeuron>();
	for (int i = 0; i < layerCount; i++) {
		int numNeurons = neuronsInLayers[i];
		std::vector<int>* neuronIndices = new std::vector<int>();
		for (int j = 0; j < numNeurons; j++) {
			SigmoidNeuron* neuron = new SigmoidNeuron();
            printf("new node made \n");
			neuronIndices->push_back(this->adjList->insert(neuron));
		}
		this->neuronLayers.push_back(neuronIndices);
	}

	for (int i = 0; i < this->neuronLayers.size() - 1; i++) {
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
		std::vector<double> outputError = vectorSubtract(output, expectedOutput);
        std::vector<int>* outputLayerNodeIndices = this->neuronLayers.at(destLayerIndex);
		for (int k = 0; k < outputError.size(); k++) {
			outputError.at(k) *= (output.at(k) * (1 - output.at(k)));
			applyWeightDelta(input, outputError.at(k), outputLayerNodeIndices->at(k));
		}
		return outputError;
	}
	

	std::vector<double> forwardLayerDelta = this->propagate(output, expectedOutput, destLayerIndex, destLayerIndex + 1);
	
	/*
	The error coming from the forward layer is known.
	Unwinding the stack accesses each layer and its input in reverse succession.
	With the layer's input and forward error known, weight deltas can be applied
	*/
	std::vector<double> delta_j;
	
	for (int i = 0; i < destNodeIndices->size(); i++) {
		std::vector<double> backWeights = this->adjList->getBackEdgeWeights(destNodeIndices->at(i));
        std::vector<int>* destLayerNodeIndices = this->neuronLayers.at(destLayerIndex);
        double dotp = dotProduct(backWeights, forwardLayerDelta);
		double currentLayerDelta = dotp * output.at(i) * (1 - output.at(i));
		delta_j.push_back(currentLayerDelta);
		applyWeightDelta(input, currentLayerDelta, destLayerNodeIndices->at(i));
	}

	return delta_j;
}

void NeuralNetwork::applyWeightDelta(std::vector<double> origOutput, double delta_j, int destNodeIndex)
{
//    printf("delta_j: %f\n", delta_j);
//    for(int i = 0; i < origOutput.size(); i++) {
//        printf("output at %d: %f\n", i, origOutput.at(i));
//    }
	std::vector<double> backWeights = this->adjList->getBackEdgeWeights(destNodeIndex);
	for (int i = 0; i < backWeights.size(); i++) {
		double weightDelta_i = this->trainingSpeedFactor * origOutput.at(i) * delta_j * (-1);
        printf("node: %d edge: %d weight delta: %f \n", destNodeIndex, i, weightDelta_i);
		backWeights.at(i) += weightDelta_i;
	}
    this->adjList->setBackEdgeWeights(backWeights, destNodeIndex);
}

int NeuralNetwork::getNumLayers()
{
	return this->neuronLayers.size();
}