#pragma once
#include <vector>
#include "AdjacencyListEdge.h"
#include "AdjacencyListNode.h"
#include <cstdlib>

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
        edge->setWeight((double)(rand()/double(RAND_MAX)));
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

    std::vector<AdjacencyListNode<T>*> getNodes()
    {
        return this->nodes;
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

    void setBackEdgeWeights(std::vector<double> weights, int ndIndex)
    {
        this->nodes.at(ndIndex)->setBackEdgeWeights(weights);
    }
};
