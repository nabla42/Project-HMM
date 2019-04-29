#pragma once
#include <vector>
#include <iostream>

//#include "trainingHMM.h"
	static size_t alphSize = 26;
class Matrix
{
	size_t height, weight;
	std::vector<double> subMatrix;
	
	void makeMatrix();	

public:
	std::vector<std::vector<double>> matrix;
	//std::vector<std::vector<double>> getMatrix();
	void showMatrix();
	Matrix(size_t height = alphSize, size_t weight = alphSize);
	~Matrix();
};

