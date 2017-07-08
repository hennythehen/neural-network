#pragma once
#include "Node.h"
#include "AdjacencyListEdge.h"
#include <vector>

template<typename T>
class AdjacencyListNode : public Node<T>
{
private:
	std::vector<AdjacencyListEdge<T>> edges;
	int listIndex;
public:
	AdjacencyListNode(T*);
	int getListIndex();
};

