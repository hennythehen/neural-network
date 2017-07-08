#include "AdjacencyListNode.h"

template <typename T>
AdjacencyListNode<T>::AdjacencyListNode(T *value)
{
	this->element = value;
}

template <typename T>
int AdjacencyListNode<T>::getListIndex()
{
	return this->listIndex;
}
