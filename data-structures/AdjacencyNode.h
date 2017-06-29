#pragma once
#include "Node.h"
template<typename T>
class AdjacencyNode :
	public Node<T>
{
private:
	int listIndex;
public:
	int getListIndex();
	AdjacencyNode();
	~AdjacencyNode();
};

