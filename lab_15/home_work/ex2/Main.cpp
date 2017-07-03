#include <iostream>
#include "FrequencyDictionary.h"

int main(){
	setlocale(0, "");
	FrequencyDictionary fd("dictionary.txt");

	fd.getTheMostFrequentWord();
	fd.getTheMostRareWord();
	fd.getRankWord(100);
	fd.getRankAndFrequent("дом");
	fd.getRankRangeWords(1, 100);
	fd.getInfoPartOfSpeach("conj");
	fd.getInfoPartOfSpeachByRank("conj", 800);
	fd.getStatiscit();

	return 0;
}