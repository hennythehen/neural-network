#pragma once
template<typename T>
class Node
{
protected:
	T* element;
public:
	Node() {}
	Node(T* element)
	{
		this->element = element;
	}

	T* getElement()
	{
		return this->element;
	}
};

