#pragma once
#include "Node.h"
#include "AdjacencyListEdge.h"
#include <vector>

template<typename T>
class AdjacencyListNode : public Node<T>
{
private:
	std::vector<AdjacencyListEdge<T>*> forwardEdges;
	std::vector<AdjacencyListEdge<T>*> backEdges;
	int listIndex;
public:
	AdjacencyListNode(T* value)
	{
		this->element = value;
	}
	
	void connectForwardEdge(AdjacencyListEdge<T>* edge)
	{
		this->forwardEdges.push_back(edge);
	}

	void connectBackEdge(AdjacencyListEdge<T>* backEdge)
	{
		this->backEdges.push_back(backEdge);
	}

	std::vector<AdjacencyListEdge<T>*> getForwardEdges()
	{
		return this->forwardEdges;
	}

	std::vector<AdjacencyListEdge<T>*> getBackEdges()
	{
		return this->backEdges;
	}

	int getListIndex()
	{
		return this->listIndex;
	}
};

