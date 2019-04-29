#include "textManipulation.h"
#include <random>

std::vector<std::string> TextManipulation::getWordList() {return words;}
std::vector<std::string> TextManipulation::getTrainingSet() { return trainingSet; };
std::vector<std::string> TextManipulation::getTestSet() { return testSet; };
std::vector<std::string> TextManipulation::getCorruptedTestSet() { return corruptedTestSet; };
std::vector<std::string> TextManipulation::getCorruptedTrainingSet(){ return corruptedTrainingSet; };

void  TextManipulation::show(std::vector<std::string> &str) {
	for (size_t i = 0; i < str.size(); ++i) {
		std::cout << str[i] << " ";
	}
}

void  TextManipulation::showWordList() {
	std::cout << "\nWord List\n";
	show(words);
}
void  TextManipulation::showCorruptedTrainingSet() {
	std::cout << "\nCorrupted Training Set\n";
	show(corruptedTrainingSet);
}
void  TextManipulation::showCorruptedTestSet() {
	std::cout << "\nCorrupted Test Set\n";
	show(corruptedTestSet);
}



void  TextManipulation::makeWordList() {
	doc.open(path);
	if (!doc.is_open()) {								// Переделаю под try-catch-trow.
		std::cout << "Failed to open file: " << path << std::endl;
	}
	else {
		std::cout << "Open file: " << path << "\n\n";
		std::string str;
		while (!doc.eof()) {
			str = "";
			doc >> str;
			for (size_t j = 0; j < str.length(); j++) { 
				if (isalpha(str[j])) {					
					str[j] = tolower(str[j]);
				}
				else { 
					str.erase(j, 1); 
					j = j-1;
				}
			}
			if (!str.empty()) {
				words.push_back(str);
			}
			
		}
	}
	doc.close();
}
// Деление на выборки.
void  TextManipulation::makeSets() {						
	size_t index = round(0.8 * words.size());
	for (size_t i = 0; i < index; i++) {
		trainingSet.push_back(words[i]);
	}
	for (size_t j = index; j < words.size(); j++) {
		testSet.push_back(words[j]);
	}
}
void  TextManipulation::corrupt(std::vector<std::string> strSet, std::vector<std::string> &strGet) {
	for (auto i = 0; i < strSet.size(); i++) { // Копируем исходный вектор. (size_t ~ auto?)
		strGet.push_back(strSet[i]);
	}
	// Нормальный рандомизатор.
	std::random_device dev;
	std::mt19937 rng(dev());

	for (size_t i = 0; i < strGet.size(); i++) {
		for (size_t j = 0; j < strGet[i].length(); j++) {
			std::uniform_real_distribution<double> randNum(0.0, 1.0);
			if (randNum(rng) < 0.2) {
				std::uniform_int_distribution<std::mt19937::result_type> randChoice(0, surroundingChars[strGet[i][j]].size() - 1);
				strGet[i][j] = surroundingChars[strGet[i][j]][randChoice(rng)];
			}
		}
	}
}

TextManipulation::TextManipulation(std::string path)
{
	this->path = path;
	makeWordList();
	makeSets();
	corrupt(trainingSet, corruptedTrainingSet);
	corrupt(testSet, corruptedTestSet);
}


TextManipulation::~TextManipulation()
{ 
	path.clear();
	words.clear();
	trainingSet.clear(); 
	testSet.clear();
	corruptedTrainingSet.clear(); 
	corruptedTestSet.clear();
}
