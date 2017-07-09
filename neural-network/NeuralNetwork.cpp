#include "NeuralNetwork.h"
#include "AdjacencyList.h"

NeuralNetwork::NeuralNetwork(int layerCount, int* const neuronsInLayer)
{
	this->adjList = new AdjacencyList<SigmoidNeuron>();
	std::vector<int> inputLayerIndices;
	int numNeurons = neuronsInLayer[0];

	while (numNeurons > 0) {
		numNeurons -= 1;
		SigmoidNeuron* n = new SigmoidNeuron();
		int index = this->adjList->insert(n);

	}
	for (int i = 1; i < layerCount-1; i++) {
		numNeurons = neuronsInLayer[i];
		while (numNeurons > 0) {
			numNeurons -= 1;
			SigmoidNeuron* n = new SigmoidNeuron();
			int index = this->adjList->insert(n);
		}
	}
}