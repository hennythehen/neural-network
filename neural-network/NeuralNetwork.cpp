#include "NeuralNetwork.h"
#include <stdexcept>

NeuralNetwork::NeuralNetwork(int layerCount, int neuronsInLayer[])
{
	std::vector<int> inputLayerIndices;
	int numNeurons = neuronsInLayer[0];
	while (numNeurons > 0) {
		numNeurons -= 1;
		SigmoidNeuron n;
		int index = this->adjList.insert(n);

	}
	for (int i = 1; i < layerCount-1; i++) {
		numNeurons = neuronsInLayer[i];
		while (numNeurons > 0) {
			numNeurons -= 1;
			SigmoidNeuron n;
			this->adjList.insert(n);
		}
	}
}