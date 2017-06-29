#include "AdjacencyListEdge.h"
template<typename T>
AdjacencyListEdge<T>::AdjacencyListEdge()
{
}

//template<typename T>
//Node<T> AdjacencyListEdge<T>::forward()
//{
//	return *this->forwardNode;
//}
//
//template<typename T>
//void AdjacencyListEdge<T>::setForward(const Node<T> &nd)
//{
//	this->forwardNode = nd;
//}
//
//template<typename T>
//void AdjacencyListEdge<T>::setForward(T val)
//{
//	Node<T> nd = new Node<T>(&val);
//	this->forwardNode = &nd;
//}
//
//
//template<typename T>
//Node<T> AdjacencyListEdge<T>::backward()
//{
//	return this->backwardNode;
//}
//
//template<typename T>
//void AdjacencyListEdge<T>::setBackward(const Node<T> nd) {
//	this->backwardNode = nd;
//}
//
//template<typename T>
//void AdjacencyListEdge<T>::setBackward(T val)
//{
//	Node<T> nd = new Node<T>(val);
//	this->backwardNode = &nd;
//}

template<typename T>
AdjacencyListEdge<T>::~AdjacencyListEdge()
{
}
