#pragma once
#include <vector>

template<typename T>
class Layer
{
private:
	std::vector<int> nodeIndices;
	Layer* forwardLayer;
	Layer* prevLayer;
public:
	int size();
	std::vector<double> propagate;
	Layer* getForwardLayer();
	Layer* getPrevLayer();
	Layer(std::vector<int> nodeIndices);
	~Layer();
};
