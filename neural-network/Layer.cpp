#include "Layer.h"

template <typename T>
Layer<T>* Layer<T>::getForwardLayer()
{
	return this->forwardLayer;
}

template <typename T>
Layer<T>* Layer<T>::getPrevLayer()
{
	return this->prevLayer;
}

template<typename T>
Layer<T>::~Layer()
{
}
