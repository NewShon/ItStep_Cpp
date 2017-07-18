#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <algorithm>

int main() {
	setlocale(0, "");


	std::ifstream in("Lopatin_dictionary.txt");
	std::unordered_map<std::string, std::string> map;
	std::string tmp;
	
	while (in >> tmp) {
		std::string sort_tmp = tmp;
		sort(sort_tmp.begin(), sort_tmp.end());
		map[tmp] = sort_tmp;
	}

	std::string word = "рондо";
	sort(word.begin(), word.end());
	for (auto& el : map) {
		if (word == el.second) {
			std::cout << el.first << std::endl;
		}
	}


	std::string word2 = "*р?ж?н*";

	
	



	return 0;
}
