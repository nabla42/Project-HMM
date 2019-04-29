#pragma once
#include "matrix.h"
#include "trainingHMM.h"
class Viterbi
{
	std::vector<std::string> correctedText;
	void correct(std::vector<std::string> corruptedSet, Matrix emissionProb, Matrix transitionProb, Matrix distribution);
	
public:
	std::vector<std::string> getCorrectedText();
	void showCorrect(std::vector<std::string> str);

	Viterbi(std::vector<std::string> corruptedSet, Matrix emissionProb, Matrix transitionProb, Matrix distribution);
	~Viterbi();
};

