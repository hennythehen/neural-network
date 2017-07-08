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
	int insert(T*);
	void connect(int orig, int dest);
	void connect(int orig, int dest[]);
	void connect(int orig[], int dest);
	void connect(int orig[], int dest[]);
	std::vector<Node<T>> getConnectedNodes(int ndIndex);
	std::vector<T> getConnectedNodeValues(int ndIndex);
	std::vector<AdjacencyListEdge<T>> getConnectedEdges(int ndIndex);
};
