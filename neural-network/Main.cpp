#include "NeuralNetwork.h"
#include <iostream>
using namespace std;

int main()
{
	int layerCount = 10;
	int layers[] = { 2, 3, 3, 3, 5, 3, 3, 3, 3, 3 };
	NeuralNetwork ann(layerCount, layers);
	
	cout << "Testing \n";

	system("pause");
}