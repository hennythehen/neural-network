#pragma once
template<typename T>
class Node
{
protected:
	T* element;
public:
	Node(T);
	T* getElement();
};

