#include "AdjacencyList.h"
#include "AdjacencyNode.h"
#include <vector>

template<typename T>
AdjacencyList<T>::AdjacencyList()
{
}

template<typename T>
int AdjacencyList<T>::insert(T value) {
	AdjacencyNode<T> nd = new AdjacencyNode<T>(value);
	this->nodes.push_back(nd);
	return this->nodes.size() - 1;
}

template <typename T>
void AdjacencyList<T>::connect(int orig, int dest)
{
	AdjacencyListEdge<T> edge;
	edge.setOriginNode(&(this->nodes.at(orig)));
	edge.setForwardNode(&(this->nodes.at(dest)));
}

template <typename T>
void AdjacencyList<T>::connect(int orig, int dest[])
{
	for (int i = 0; i < sizeof(dest) / sizeof(dest[0]); i++) {
		this->connect(orig, dest[i]);
	}
}

template <typename T>
void AdjacencyList<T>::connect(int orig[], int dest)
{
	for (int i = 0; i < sizeof(orig) / sizeof(orig[0]); i++) {
		this->connect(orig[i], dest);
	}
}

template <typename T>
void AdjacencyList<T>::connect(int orig[], int dest[])
{
	for (int i = 0; i < sizeof(orig) / sizeof(orig[0]); i++) {
		for (int j = 0; j < sizeof(dest) / sizeof(dest[0]); j++) {
			this->connect(orig[i], dest[j]);
		}
	}
}

template<typename T>
std::vector<Node<T>> AdjacencyList<T>::getConnectedNodes(int ndIndex)
{
	std::vector<AdjacencyListEdge<T>> edges = this->list.at(ndIndex);
	std::vector<Node<T>> nodes;
	for (int i = 0; i < this->edges.size(); i++) {
		AdjacencyListEdge<T> e = edges.at(i);
		nodes.insert(e.forward);
	}
	return nodes;
}

template<typename T>
std::vector<T> AdjacencyList<T>::getConnectedNodeValues(int ndIndex)
{
	std::vector<Node<T>> nodes = this->getConnectedNodes;
	std::vector<T> values;
	for (int i = 0; i < nodes.size(); i++) {
		Node<T> nd = nodes.at(i);
		values.insert(nd.getElement());
	}
	return values;
}

template<typename T>
std::vector<AdjacencyListEdge<T>> AdjacencyList<T>::getConnectedEdges(int ndIndex)
{
	return this->list->at(ndIndex);
}

template<typename T>
AdjacencyList<T>::~AdjacencyList()
{
}
