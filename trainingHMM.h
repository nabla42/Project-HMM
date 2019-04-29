#pragma once
#include <vector>
#include "textManipulation.h"
#include "matrix.h"
class TrainingHMM
{
	int roundAcc = 10000;
	Matrix emissionProb;
	Matrix transitionProb;
	Matrix distribution = 1;	

	void makeEmission(std::vector<std::string>trainingSet, std::vector<std::string>corruptedSet);
	void makeTransistion(std::vector<std::string>trainingSet);
	void makeDistribution(std::vector<std::string>trainingSet);
	double sum(std::vector<double>vec);	

public:
	Matrix getEmiss();
	Matrix getTrans();
	Matrix getDist();
	TrainingHMM(std::vector<std::string> trainingSet, std::vector<std::string> corruptedTrainingSet);
	~TrainingHMM();
};

