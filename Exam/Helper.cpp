#include "Helper.h"
#include <fstream>
#include <iostream>
#include <algorithm>



void CrosswordSolver::readDocument(std::string doc_name){
	map_dictionary.clear();
	
	std::ifstream in(doc_name);
	if (!in.is_open()){
		std::cout << "File open Error!!!" << std::endl;
		return;
	}

	std::string tmp;
	std::string sort_tmp;
	while (in >> tmp){
		sort_tmp = tmp;
		sort(sort_tmp.begin(), sort_tmp.end());
		map_dictionary[tmp] = sort_tmp;
	}

	in.close();
}
void CrosswordSolver::getAllWithLen(size_t word_len){
	std::ofstream out("AllWithLen.txt");
	if (!out.is_open()){
		std::cout << "File creation Error!!!" << std::endl;
		return;
	}

	for (auto& word : map_dictionary){
		if (word.first.length() == word_len){
			out << word.first << std::endl;
		}
	}

	out.close();
}
void CrosswordSolver::getAllWithInit(char letter){
	std::ofstream out("AllWithInit.txt");
	if (!out.is_open()){
		std::cout << "File creation Error!!!" << std::endl;
		return;
	}

	for (auto& word : map_dictionary){
		if (word.first[0] == letter){
			out << word.first << std::endl;
		}
	}

	out.close();
}
void CrosswordSolver::findByMask(std::string mask){
	bool flag = true;
	for (size_t i = 0; i < mask.length(); ++i){
		if (mask[i] != '*' && mask[i] != '?'){
			flag = false;
			break;
		}
	}
	if (flag == true){
		std::ofstream out("WordsByMask.txt");
		if (!out.is_open()){
			std::cout << "File creation Error!!!" << std::endl;
			return;
		}
		for (auto& word : map_dictionary){
			out << word.first << std::endl;
		}
		return;
	}

	std::vector<std::string> words_by_mask;

	for (auto& word : map_dictionary){
		if (mask.length() > word.first.length()){
			continue;
		}
		size_t mask_it = 0;
		size_t word_it = 0;

		while (mask[mask_it] == '*' || mask[mask_it] == '?'){
			++mask_it;
		}

		while (word.first[word_it] != mask[mask_it] && word_it < word.first.length()){
			++word_it;
		}
		if (word.first[word_it] != mask[mask_it]){
			continue;
		}

		flag = true;
		std::string tmp_mask = "";
		while (mask_it < mask.length() && word_it < word.first.length()){
			tmp_mask += word.first[word_it];

			if (mask[mask_it] == '*' || mask[mask_it] == '?'){
				++mask_it;
				++word_it;
				continue;
			}
			if (mask[mask_it] != word.first[word_it]){
				flag = false;
				break;
			}
			++mask_it;
			++word_it;
		}

		if (word_it == word.first.length() && mask_it != mask.length()){
			flag = false;
		}
		if (flag == false){
			continue;
		}

		if (flag == true) {
			if (mask[0] == '*' && mask[mask.length() - 1] == '*'){
				words_by_mask.push_back(word.first);
			}
			else if (mask[mask.length() - 1] == '*'){
				if (std::equal(word.first.begin(), word.first.begin() + tmp_mask.length(), tmp_mask.begin())) {
					words_by_mask.push_back(word.first);
				}
			}
			else if (mask[0] == '*'){
				if (std::equal(word.first.rbegin(), word.first.rbegin() + tmp_mask.length(), tmp_mask.rbegin())) {
					words_by_mask.push_back(word.first);
				}
			}
			else{
				if (mask.length() == word.first.length()){
					words_by_mask.push_back(word.first);
				}
			}
		}
	}

	if (words_by_mask.size() > 20){
		std::ofstream out("WordsByMask.txt");
		if (!out.is_open()){
			std::cout << "File creation Error!!!" << std::endl;
			return;
		}
		for (auto& word : words_by_mask){
			out << word << std::endl;
		}
	}
	else{
		for (auto& word : words_by_mask){
			std::cout << word << std::endl;
		}
	}
}

void CrosswordSolver::getAnagrams(std::string word){
	std::ofstream out("Anagrams.txt");
	if (!out.is_open()){
		std::cout << "File creation Error!!!" << std::endl;
		return;
	}

	std::string tmp_word = word;
	sort(tmp_word.begin(), tmp_word.end());
	for (auto& el : map_dictionary) {
		if (word != el.first && tmp_word == el.second) {
			out << el.first << std::endl;
		}
	}
}