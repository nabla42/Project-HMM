#include <iostream>
#include "textManipulation.h"
#include "matrix.h"
#include "trainingHMM.h"
#include "viterbi.h"
#include "process.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	TextManipulation* t = new TextManipulation("text/bigtest.txt");//testdata.txt");
	//t.showCorruptedTrainingSet();
	//t.showCorruptedTestSet();
	// TextManipulation - ok!

	TrainingHMM *thm = new TrainingHMM((*t).getTrainingSet(), (*t).getCorruptedTrainingSet());
	//TrainingHMM - ok!

	Viterbi* vit = new Viterbi((*t).getCorruptedTestSet(), (*thm).getEmiss(), (*thm).getTrans(), (*thm).getDist());
	// Не так хорошо, как хотелось бы..

	Process* pr = new Process((*t).getCorruptedTestSet(), (*t).getTestSet(), (*vit).getCorrectedText());
	(*pr).showStat();
	// Есть сомнения.
}

