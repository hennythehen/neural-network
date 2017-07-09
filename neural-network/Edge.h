#pragma once
#include "Node.h"

template <typename T>
class Edge
{
protected:
	double weight;
	Node<T>* originNode;
	Node<T>* forwardNode;
public:
	Edge()
	{

	}

	void setOriginNode(Node<T>* nd)
	{
		this->originNode = nd;
	}

	Node<T>* getOriginNode()
	{
		return this->originNode;
	}

	void setForwardNode(Node<T>* nd)
	{
		this->forwardNode = nd;
	}

	Node<T>* getForwardNode()
	{
		return this->forwardNode;
	}

	double getWeight()
	{
		return this->weight;
	}

	void setWeight(double weight)
	{
		this->weight = weight;
	}
};
