#pragma once
#include <vector>
#include <cmath>

template <typename T>
double dotProduct(std::vector<T> v1, std::vector<T> v2)
{
	double dp = 0;
	for (int i = 0; i < v1.size() && i < v1.size(); i++) {
		dp += (v1.at(i) * v2.at(i));
	}
	return dp;
}

template<typename T>
std::vector<double> vectorSubtract(std::vector<T> v1, std::vector<T>v2)
{
	std::vector<double> result;
	for (int i = 0; i < v1.size() && i < v2.size(); i++) {
		result.push_back(v1.at(i) - v2.at(i));
	}
	return result;
}

template<typename T>
double vectorNorm(std::vector<T> v1)
{
	double norm = 0;
	for (int i = 0; i < v1.size(); i++) {
		norm += (v1.at(i) + v1.at(i));
	}
	return sqrt(norm);
}