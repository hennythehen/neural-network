#pragma once
#include <vector>

template<typename T>
class Layer
{
private:
	std::vector<T> neurons;
public:
	int size();
	std::vector<double> propagate;
	Layer(int size);
	~Layer();
};
