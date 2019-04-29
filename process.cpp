#include "process.h"


// Этот класс, в итоге, можно сделать "Фасадом", или создать отдельный.

void Process::makeStat(std::vector<std::string> corruptedTestSet, std::vector<std::string> testSet, std::vector<std::string> correctedText) {
	// TP: wrong-- > correct
	// FN: wrong-- > wrong
	// TP: correct-- > wrong
	// Precision = TP / (TP + FP)	<--------------- по этому поводу - не уверена.
	// Recall = TP / (TP + FN)		<---------------	- / / -

	for (auto i = 0; i < correctedText.size(); ++i) {
		totalWord += 1;
		if (corruptedTestSet[i] != testSet[i]) {
			if (correctedText[i]== testSet[i]) {
				TP += 1;
			}
			else if (correctedText[i] != testSet[i])
			{
				FN += 1;
			}
		}
		if (corruptedTestSet[i] == testSet[i]) {
			if (testSet[i] != correctedText[i]) {
				FP += 1;
			}
		}
	}

}

void Process::showStat() {
	recall = TP / (TP + FN) * 100;
	precision = TP / (TP + FP) * 100;
	std::cout << "\nTotal Words: " << totalWord;
	std::cout << "\nTP: " << TP;
	std::cout << "\nFN: " << FN;
	std::cout << "\nFP: " << FP;
	std::cout << "\nPrecision: "<< precision;
	std::cout << "\nRecall: " << recall;
}

Process::Process(std::vector<std::string> corruptedTestSet, std::vector<std::string> testSet, std::vector<std::string> correctedText)
{
	makeStat(corruptedTestSet, testSet, correctedText);
}

Process::~Process()
{
}
