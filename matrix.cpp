#include "matrix.h"

void Matrix::makeMatrix(){
	for (size_t j = 0; j < weight; ++j) {
		subMatrix.push_back(0.0);
	}
	for (size_t i = 0; i < height; ++i) {
		matrix.push_back(subMatrix);
	}
}

//std::vector<std::vector<double>>Matrix::getMatrix() { return matrix; }
// Переделать для итератора
void Matrix::showMatrix() {
	for (auto j = 0; j < height; ++j) {
		for (size_t i = 0; i < weight; ++i) {
			std::cout << matrix[j][i]<<" ";
		}
		std::cout << "\n";
	}
}

Matrix::Matrix(size_t height, size_t weight)
{
	this->height = height;
	this->weight = weight;
	makeMatrix();
}


Matrix::~Matrix()
{
	//std::cout << "\nMatrix destructor\n";
	subMatrix.clear();
	matrix.clear();
}
