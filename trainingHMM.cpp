#include "trainingHMM.h"

double TrainingHMM::sum(std::vector<double> vec) {
	double sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	return sum;
}

void TrainingHMM::makeEmission(std::vector<std::string>trainingSet, std::vector<std::string>corruptedSet) {
	for (size_t i = 0; i < trainingSet.size(); ++i) {
		for (size_t j = 0; j < trainingSet[i].length(); ++j) {
			emissionProb.matrix[int(trainingSet[i][j]) - 97][int(corruptedSet[i][j]) - 97] += 1;
		}
	}
	// Уберем нули и приведем к вероятностям (+ округлим)
	for (size_t i = 0; i < alphSize; ++i) {
		for (size_t j = 0; j < alphSize; ++j) {
			if (emissionProb.matrix[i][j] == 0) { emissionProb.matrix[i][j] = 1; }
		}
	}
	for (size_t i = 0; i < alphSize; ++i) {
		double emissSum = sum(emissionProb.matrix[i]);
		for (size_t j = 0; j < alphSize; ++j) {						 // Внизу - округление для "вмещаемого" вывода на экран.
			emissionProb.matrix[i][j] = emissionProb.matrix[i][j] / emissSum;	//round((emissionProb.matrix[i][j] / emissSum) * roundAcc) / roundAcc;
		}
	}
};
void TrainingHMM::makeTransistion(std::vector<std::string>trainingSet) {
	for (size_t i = 0; i < trainingSet.size(); ++i) {
		for (size_t j = 0; j < trainingSet[i].length(); ++j) {
			if (j != trainingSet[i].length() - 1) {
				transitionProb.matrix[int(trainingSet[i][j]) - 97][int(trainingSet[i][j + 1]) - 97] += 1;
			}
		}
	}
	// Приводим к вероятностям
	for (size_t i = 0; i < alphSize; ++i) {
		for (size_t j = 0; j < alphSize; ++j) {
			if (transitionProb.matrix[i][j] == 0) { transitionProb.matrix[i][j] = 1; }
		}
	}
	for (size_t i = 0; i < alphSize; ++i) {
		double transSum = sum(transitionProb.matrix[i]);
		for (size_t j = 0; j < alphSize; ++j) {
			transitionProb.matrix[i][j] = transitionProb.matrix[i][j] / transSum;//round((transitionProb.matrix[i][j] / transSum) * roundAcc) / roundAcc;
		}
	}
};
void TrainingHMM::makeDistribution(std::vector<std::string>trainingSet) {
	int sum = 0; // Всего букв в тексте
	for (size_t i = 0; i < trainingSet.size(); ++i) {
		for (size_t j = 0; j < trainingSet[i].length(); ++j) {
			distribution.matrix[0][int(trainingSet[i][j]) - 97] += 1;
			sum++;
		}
	}
	// Приводим к вероятностям
	for (size_t i = 0; i < alphSize; ++i) {
		distribution.matrix[0][i] = distribution.matrix[0][i] / sum;	//round((distribution.matrix[0][i] / sum) * roundAcc) / roundAcc;
	}
};

Matrix TrainingHMM::getEmiss() { return emissionProb; }
Matrix TrainingHMM::getTrans() { return transitionProb; }
Matrix TrainingHMM::getDist() {	return distribution;}

TrainingHMM::TrainingHMM(std::vector<std::string> trainingSet, std::vector<std::string> corruptedTrainingSet)
{
	makeEmission(trainingSet, corruptedTrainingSet);
	makeTransistion(trainingSet);
	makeDistribution(trainingSet);

	//std::cout << "\nEis\n";
	//emissionProb.showMatrix();
	//std::cout << "\nAij\n";
	//transitionProb.showMatrix();
	//std::cout << "\ndist\n";
	//distribution.showMatrix();

}


TrainingHMM::~TrainingHMM()
{
}
