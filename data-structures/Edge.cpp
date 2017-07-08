#include "Edge.h"

template <typename T>
Edge<T>::Edge()
{
}

template <typename T>
void Edge<T>::setOriginNode(Node<T> &nd) {
	this->originNode = nd;
	return;
}

template <typename T>
Node<T>* Edge<T>::getOriginNode()
{
	return this->originNode;
}

template <typename T>
void Edge<T>::setForwardNode(Node<T> &nd)
{
	this->forwardNode = nd;
	return;
}

template <typename T>
Node<T>* Edge<T>::getForwardNode()
{
	return this->forwardNode;
}

template <typename T>
double Edge<T>::getWeight()
{
	return this->weight;
}

template <typename T>
void Edge<T>::setWeight(double weight)
{
	this->weight = weight;
	return;
}
