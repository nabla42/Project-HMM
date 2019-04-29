#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

class TextManipulation
{
		std::ifstream doc;
		std::string path;
		std::vector <std::string> words;
		std::vector <std::string> trainingSet, testSet;
		std::vector<std::string> corruptedTrainingSet, corruptedTestSet;
		std::map <char, std::vector<char>> surroundingChars = {
			{'a', {'q', 'w', 's', 'x', 'z'}},
			{'b', {'f', 'g', 'h', 'n', 'v'}},
			{'c', {'x', 's', 'd', 'f', 'v'}},
			{'d', {'w', 'e', 'r', 's', 'f', 'x', 'c', 'v'}},
			{'e', {'w', 'r', 's', 'd', 'f'}},
			{'f', {'e', 'r', 't', 'd', 'g', 'c', 'v', 'b'}},
			{'g', {'r', 't', 'y', 'f', 'h', 'v', 'b', 'n'}},
			{'h', {'t', 'y', 'u', 'g', 'j', 'b', 'n', 'm'}},
			{'i', {'u', 'o', 'j', 'k', 'l'}},
			{'j', {'y', 'u', 'i', 'h', 'k', 'n', 'm'}},
			{'k', {'u', 'i', 'o', 'j', 'l', 'm'}},
			{'l', {'i', 'o', 'p', 'k'}},
			{'m', {'n', 'h', 'j', 'k'}},
			{'n', {'b', 'g', 'h', 'j', 'm'}},
			{'o', {'i', 'k', 'l', 'p'}},
			{'p', {'o', 'l'}},
			{'q', {'a', 's', 'w'}},
			{'r', {'e', 'd', 'f', 'g', 't'}},
			{'s', {'q', 'w', 'e', 'a', 'd', 'z', 'x', 'c'}},
			{'t', {'r', 'y', 'f', 'g', 'h'}},
			{'u', {'y', 'i', 'h', 'j', 'k'}},
			{'v', {'d', 'f', 'g', 'c', 'b'}},
			{'w', {'q', 'e', 'a', 's', 'd'}},
			{'x', {'a', 's', 'd', 'z', 'c'}},
			{'y', {'t', 'u', 'g', 'h', 'j'}},
			{'z', {'a', 's', 'x'}}
		};

		void makeWordList();
		void makeSets();
		void corrupt(std::vector<std::string> strSet, std::vector<std::string> &strGet);


public:
		std::vector<std::string> getWordList();
		std::vector<std::string> getTrainingSet();
		std::vector<std::string> getTestSet();
		std::vector<std::string> getCorruptedTestSet();
		std::vector<std::string> getCorruptedTrainingSet();

		void show(std::vector<std::string> &str);
		void showCorruptedTestSet();
		void showCorruptedTrainingSet();
		void showWordList();

	TextManipulation(std::string path = "text/testdata.txt");
	~TextManipulation();
};

