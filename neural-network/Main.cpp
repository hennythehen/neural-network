#include "NeuralNetwork.h"
#include <iostream>
using namespace std;

int main()
{
	int layerCount = 5;
	int layers[] = { 2, 3, 3, 3, 5 };
	NeuralNetwork ann(layerCount, layers);

	cout << "Goodbye world";
	system("pause");
}