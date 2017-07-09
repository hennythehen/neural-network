#pragma once
#include <vector>
#include "AdjacencyListEdge.h"
#include "AdjacencyListNode.h"

template <typename T>
class AdjacencyList
{
private:
	std::vector<AdjacencyListNode<T>*> nodes;
public:
	int insert(T* value)
	{
		AdjacencyListNode<T>* nd = new AdjacencyListNode<T>(value);
		this->nodes.push_back(nd);
		return this->nodes.size() - 1;
	}

	void connect(int orig, int dest)
	{
		AdjacencyListEdge<T> edge;
		edge.setOriginNode(&(this->nodes.at(orig)));
		edge.setForwardNode(&(this->nodes.at(dest)));
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

	std::vector<Node<T>> getConnectedNodes(int ndIndex)
	{
		std::vector<AdjacencyListEdge<T>> edges = this->list.at(ndIndex);
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

	std::vector<AdjacencyListEdge<T>> getConnectedEdges(int ndIndex)
	{
		return this->list->at(ndIndex);
	}
};
