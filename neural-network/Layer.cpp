#include "Layer.h"

template<typename T>
Layer<T>::Layer(int size)
{
	this->neurons = std::vector<T>;
	for (int i = 0; i < size; i++) {
		this->neurons->insert(new T())
	}
}

template<typename T>
int Layer<T>::size()
{
	return this->neurons->size();
}

template<typename T>
Layer<T>::~Layer()
{
}
