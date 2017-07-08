#include "NeuralNetwork.h"
#include <stdio.h>

int main()
{
	int layerCount = 5;
	int layers[] = { 2, 3, 3, 3, 5 };
	NeuralNetwork ann(layerCount, layers);
	printf("Hello world");
}