#pragma once
#include "textManipulation.h"
#include "viterbi.h"

class Process
{
	int totalWord= 0;
	double TP = 0.0, FN = 0.0, FP = 0.0, precision = 0.0, recall = 0.0;

	void makeStat(std::vector<std::string> corruptedTestSet, std::vector<std::string> testSet, std::vector<std::string> correctedText);

public:
	void showStat();
	Process(std::vector<std::string> corruptedTestSet, std::vector<std::string> testSet, std::vector<std::string> correctedText);
	~Process();
};

