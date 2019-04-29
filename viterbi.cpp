#include "viterbi.h"

void Viterbi::correct(std::vector<std::string> corruptedSet, Matrix emissionProb, Matrix transitionProb, Matrix distribution) {

	for (size_t w = 0; w < corruptedSet.size(); ++w) {
	// Создали подконтейнеры для Т1 и Т2
	//int w = 13;
		Matrix T1(alphSize, corruptedSet[w].length());
		Matrix T2(alphSize, corruptedSet[w].length());

		double temp_max = -1;
		double temp = 0;
		int temp_k = 0;

		// 1) Для первой буквы в слове:
		for (size_t j = 0; j < alphSize; j++) {
			T1.matrix[j][0] = distribution.matrix[0][j] * emissionProb.matrix[j][int(corruptedSet[w][0]) - 97];
			T2.matrix[j][0] = 0;
		}
		// 2) Для остальных:
		for (size_t i = 1; i < corruptedSet[w].length(); i++) { // Длина слова
			for (size_t j = 0; j < alphSize; j++) {
				for (size_t k = 0; k < alphSize; k++) {
					temp = T1.matrix[k][i - 1] * transitionProb.matrix[k][j] * emissionProb.matrix[j][int(corruptedSet[w][i]) - 97];
					if (temp > temp_max) {
						temp_max = temp;
						temp_k = k;
					}
				}
				T1.matrix[j][i] = temp_max;
				T2.matrix[j][i] = temp_k;

				temp_max = -1;
				temp_k = 0;
			}
		}
		//std::cout << "\nT1\n";
		//T1.showMatrix();
		//std::cout << "\nT2\n";
		//T2.showMatrix();
		
		std::vector<int> Z(corruptedSet[w].length());
		std::vector<char> X(corruptedSet[w].length());

		for (int k = 0; k < alphSize; k++) { // Смотрим на последние буквы слова

			temp = T1.matrix[k][corruptedSet[w].length() - 1];
			if (temp > temp_max) {
				temp_max = temp;
				temp_k = k;
			}
		}
		Z[corruptedSet[w].length() - 1] = temp_k;
		X[corruptedSet[w].length() - 1] = char(temp_k + 97);

		for (int i = corruptedSet[w].length() - 1; i > 0; --i) {
			Z[i - 1] = T2.matrix[Z[i]][i];
			X[i - 1] = char(Z[i - 1] + 97);
		}
		correctedText.push_back("");
		for (int i = 0; i < X.size(); ++i) {
			correctedText[w].push_back(X[i]);
		}
	}
}

void Viterbi::showCorrect(std::vector<std::string> correctedText) {

	for (size_t i = 0; i < correctedText.size(); ++i) {
		std::cout << correctedText[i] << " ";
	}
}
std::vector<std::string> Viterbi::getCorrectedText() { return correctedText; }

Viterbi::Viterbi(std::vector<std::string> corruptedSet, Matrix emissionProb, Matrix transitionProb, Matrix distribution)
{
	correct(corruptedSet, emissionProb, transitionProb, distribution);
	//std::cout << "\n\nCorrect:\n";
	//showCorrect(correctedText);
	
}

Viterbi::~Viterbi()
{
}
