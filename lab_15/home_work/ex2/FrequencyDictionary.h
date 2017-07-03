#pragma once
#include <string>
#include <vector>

struct Info{
	float rank;
	std::string lemma;
	std::string part_of_speach;
	float fr_m;
	float fr_1;
	float fr_2;
	float fr_3;
	float fr_4;
	float fr_5;
	float fr_6;
};

class FrequencyDictionary
{
	std::vector<Info> dict;
	size_t theMostFrequentWord_counter = 0;
	size_t theMostRareWord_counter = 0;
	size_t rankWord_counter = 0;
	size_t rankAndFrequent_counter = 0;
	size_t rankRangeWords_counter = 0;
	size_t infoPartOfSpeach_counter = 0;
	size_t infoPartOfSpeachByRank_counter = 0;
	size_t statiscit_counter = 0;
public:
	FrequencyDictionary(std::string);
	~FrequencyDictionary() {}

	void getTheMostFrequentWord();
	void getTheMostRareWord();
	void getRankWord(size_t);
	void getRankAndFrequent(std::string);
	void getRankRangeWords(size_t, size_t);
	void getInfoPartOfSpeach(std::string);
	void getInfoPartOfSpeachByRank(std::string, size_t);
	void getStatiscit();
};

