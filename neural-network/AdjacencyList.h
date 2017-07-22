#pragma once
#include <vector>
#include "AdjacencyListEdge.h"
#include "AdjacencyListNode.h"

template <typename T>
class AdjacencyList
{
private:
	std::vector<AdjacencyListNode<T>*> nodes;
	std::vector<double> extractWeights(std::vector<AdjacencyListEdge<T>*> edges)
	{
		std::vector<double> weights;
		for (int i = 0; i < edges.size(); i++) {
			AdjacencyListEdge<T>* e = edges.at(i);
			weights.push_back(e->getWeight());
		}
		return weights;
	}
public:
	int insert(T* value)
	{
		AdjacencyListNode<T>* nd = new AdjacencyListNode<T>(value);
		this->nodes.push_back(nd);
		return this->nodes.size() - 1;
	}

	T* element(int index)
	{
		AdjacencyListNode<T>* nd = this->nodes.at(index);
		return nd->getElement();
	}

	void connect(int orig, int dest)
	{
		AdjacencyListEdge<T>* edge = new AdjacencyListEdge<T>();
		AdjacencyListNode<T>* origNd = this->nodes.at(orig);
		AdjacencyListNode<T>* destNd = this->nodes.at(dest);
		edge->setOriginNode(this->nodes.at(orig));
		edge->setForwardNode(this->nodes.at(dest));
		origNd->connectForwardEdge(edge);
		destNd->connectBackEdge(edge);
	}

	void connect(int orig, int dest[])
	{
		for (int i = 0; i < sizeof(dest) / sizeof(dest[0]); i++) {
			this->connect(orig, dest[i]);
		}
	}

	void connect(int orig[], int dest)
	{
		for (int i = 0; i < sizeof(orig) / sizeof(orig[0]); i++) {
			this->connect(orig[i], dest);
		}
	}

	void connect(int orig[], int dest[])
	{
		for (int i = 0; i < sizeof(orig) / sizeof(orig[0]); i++) {
			for (int j = 0; j < sizeof(dest) / sizeof(dest[0]); j++) {
				this->connect(orig[i], dest[j]);
			}
		}
	}

	void connect(std::vector<int>* orig, std::vector<int>* dest)
	{
		for (int i = 0; i < orig->size(); i++) {
			for (int j = 0; j < dest->size(); j++) {
				this->connect(orig->at(i), dest->at(j));
			}
		}

	}

	std::vector<AdjacencyListNode<T>*> getForwardNodes(int ndIndex)
	{
		AdjacencyListNode<T>* nd = this->nodes.at(ndIndex);
		nd->
	}

	std::vector<AdjacencyListNode<T>*> getNode(std::vector<int> indices)
	{
		std::vector<AdjacencyListNode<T>> 
	}

	std::vector<AdjacencyListNode<T>*> getConnectedNodes(int ndIndex)
	{
		AdjacencyListNode<T>* nd = this->nodes.at(ndIndex);
		std::vector<AdjacencyListEdge<T>*> edges = this->list.at(ndIndex);
		std::vector<Node<T>> nodes;
		for (int i = 0; i < this->edges.size(); i++) {
			AdjacencyListEdge<T> e = edges.at(i);
			nodes.insert(e.forward);
		}
		return nodes;
	}

	std::vector<T> getConnectedNodeValues(int ndIndex)
	{
		std::vector<Node<T>> nodes = this->getConnectedNodes;
		std::vector<T> values;
		for (int i = 0; i < nodes.size(); i++) {
			Node<T> nd = nodes.at(i);
			values.insert(nd.getElement());
		}
		return values;
	}

	std::vector<double> getForwardEdgeWeights(int ndIndex)
	{
		AdjacencyListNode<T>* nd = this->nodes.at(ndIndex);
		return this->extractWeights(nd->getForwardEdges());
	}

	std::vector<double> getBackEdgeWeights(int ndIndex)
	{
		AdjacencyListNode<T>* nd = this->nodes.at(ndIndex);
		return this->extractWeights(nd->getBackEdges());
	}
};
