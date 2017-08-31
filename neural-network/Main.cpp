#include "NeuralNetwork.h"
#include <iostream>
using namespace std;

int main()
{
	int layerCount = 3;
	int layers[] = { 2, 3, 2 };
	NeuralNetwork ann(layerCount, layers);
    ann.dumpWeights();
    std::vector<double> i; i.push_back(0.4); i.push_back(0.1);
    std::vector<double> o; o.push_back(0.9); o.push_back(0.3);
    ann.train(i, o);
    printf("TRAINED\n");
    ann.dumpWeights();
	cout << "Testing \n";

	system("pause");
}