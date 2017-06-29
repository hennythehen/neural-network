#pragma once

#include <vector>
#include "AdjacencyListEdge.h"
template<typename T>
class AdjacencyList
{
private:
	std::vector<std::vector<AdjacencyListEdge<T>>> edgeVectors;
	std::vector<Node<T>> nodes;
public:
	AdjacencyList();
	int insert(T val);
	void connect(int orig, int dest);
	void connect(int orig, int dest[]);
	void connect(int orig[], int dest);
	void connect(int orig[], int dest[]);
	std::vector<Node<T>> getConnectedNodes(int ndIndex);
	std::vector<T> getConnectedNodeValues(int ndIndex);
	std::vector<AdjacencyListEdge<T>> getConnectedEdges(int ndIndex);
	~AdjacencyList();
};
