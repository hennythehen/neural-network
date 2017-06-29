#include "Node.h"


template<typename T>
Node<T>::Node(T val)
{
}

template<typename T>
T Node<T>::getElement()
{
	return *this.element;
}

template<typename T>
Node<T>::~Node()
{
}
