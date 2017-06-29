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
	Edge();
	void setOriginNode(Node<T> &nd);
	Node<T>* getOriginNode();
	void setForwardNode(Node<T> &nd);
	Node<T>* getForwardNode();
	double getWeight();
	void setWeight(double weight);
	~Edge();
};
