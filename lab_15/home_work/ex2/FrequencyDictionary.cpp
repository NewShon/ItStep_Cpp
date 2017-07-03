#include "FrequencyDictionary.h"
#include <fstream>
#include <iostream>
#include <map>
#include <array>


FrequencyDictionary::FrequencyDictionary(std::string file_name){
	std::ifstream in(file_name);
	if (!in.is_open()){
		std::cout << "File error\n";
		return;
	}

	Info tmp;
	while (!in.eof()){
		in >> tmp.rank;
		in >> tmp.lemma;
		in >> tmp.part_of_speach;
		in >> tmp.fr_m;
		in >> tmp.fr_1;
		in >> tmp.fr_2;
		in >> tmp.fr_3;
		in >> tmp.fr_4;
		in >> tmp.fr_5;
		in >> tmp.fr_6;

		dict.push_back(tmp);
	}
}

void FrequencyDictionary::getTheMostFrequentWord(){
	std::string name = "Info/TheMostFrequentWord_" + 
		std::to_string(theMostFrequentWord_counter++) + ".txt";
	std::ofstream out(name);

	 out << dict.front().lemma;
}
void FrequencyDictionary::getTheMostRareWord(){
	std::string name = "Info/TheMostRareWord_" +
		std::to_string(theMostRareWord_counter++) + ".txt";
	std::ofstream out(name);

	out << dict.back().lemma;
}
void FrequencyDictionary::getRankWord(size_t rank){
	std::string name = "Info/RankWord_" +
		std::to_string(rankWord_counter++) + ".txt";
	std::ofstream out(name);

	out << dict.at(rank - 1).lemma;
}
void FrequencyDictionary::getRankAndFrequent(std::string word){
	std::string name = "Info/RankAndFrequent_" +
		std::to_string(rankAndFrequent_counter++) + ".txt";
	std::ofstream out(name);

	for (auto& el : dict){
		if (el.lemma == word){
			out << el.rank << " " << el.fr_m;
		}
	}
}
void FrequencyDictionary::getRankRangeWords(size_t begin, size_t end){
	std::string name = "Info/RankRangeWords_" +
		std::to_string(rankRangeWords_counter++) + ".txt";
	std::ofstream out(name);

	if (begin < dict.front().rank || end > dict.back().rank){
		std::cout << "Out of range" << std::endl;
	}
	for (size_t i = begin -1; i < end; ++i){
		out << dict[i].rank << " " << dict[i].lemma << std::endl;
	}
}
void FrequencyDictionary::getInfoPartOfSpeach(std::string part_name){
	std::string name = "Info/InfoPartOfSpeach_" +
		std::to_string(infoPartOfSpeach_counter++) + ".txt";
	std::ofstream out(name);

	for (auto& el : dict){
		if (el.part_of_speach == part_name){
			out << el.rank << " " << el.fr_m << " " << el.lemma << std::endl;
		}
	}
}
void FrequencyDictionary::getInfoPartOfSpeachByRank(std::string part_name, size_t freq){
	std::string name = "Info/InfoPartOfSpeachByRank_" +
		std::to_string(infoPartOfSpeachByRank_counter++) + ".txt";
	std::ofstream out(name);

	for (auto& el : dict){
		if (el.part_of_speach == part_name && el.fr_m > freq){
			out << el.rank << " " << el.fr_m << " " << el.lemma << std::endl;
		}
	}

}

void FrequencyDictionary::getStatiscit(){
	std::string name = "Info/Statiscit_" +
		std::to_string(statiscit_counter++) + ".txt";
	std::ofstream out(name);

	std::map < std::string, std::array<double, 2>> tmp;
	for (auto & el : dict){
		++tmp[el.part_of_speach][0];
		tmp[el.part_of_speach][1] += el.fr_m;
	}

	for (auto& el : tmp){
		out << el.first << " " << el.second[0] << " " << el.second[1]/el.second[0] << std::endl;
	}
}