#include "FrequencyDictionary.h"

int main(){
	setlocale(0, "");

	FrequencyDictionary fq("turgenev.txt");

	fq.showFreqDict();
	fq.showMaxFreq();
	fq.recordFile();

	return 0; 
}