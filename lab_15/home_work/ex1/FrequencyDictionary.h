#pragma once
#include <string>
#include <map>
#include <fstream>
#include <iostream>

class FrequencyDictionary
{
	std::map<std::string, size_t> mp;
	std::multimap<size_t, std::string> mlmp;
public:
	FrequencyDictionary(std::string file_name){
		readFile(file_name);
	}
	~FrequencyDictionary() {}


	void readFile(std::string file_name){
		mp.clear();

		std::ifstream in(file_name);
		if (!in.is_open()){
			std::cout << "File open Error" << std::endl;
			return;
		}

		std::string tmp_str;
		while (in >> tmp_str){
			if (tmp_str[tmp_str.length() - 1] >= 'à' || tmp_str[tmp_str.length() - 1] <= 'ÿ'){
				if (mp.find(tmp_str) != mp.end()){
					++mp[tmp_str];
					continue;
				}
				else{
					mp[tmp_str] = 0;
					continue;
				}

			}
			if (isalnum(tmp_str[tmp_str.length() - 1])){
				if (mp.find(tmp_str) != mp.end()){
					++mp[tmp_str];
					continue;
				}
				else{
					mp[tmp_str] = 0;
					continue;
				}
			}
		}

		for (auto& el : mp){
			mlmp.insert({ el.second, el.first });
		}

		in.close();
	}

	void showFreqDict(){
		for (auto& el : mlmp){
			std::cout << el.second << " " << el.first << std::endl;
		}
	}

	void showMaxFreq(){
		std::cout << mlmp.rbegin()->second << " " << mlmp.rbegin()->first << std::endl;
	}

	void recordFile(){
		std::ofstream out("FrequencyDictionary.txt");
		for (auto it = mlmp.rbegin(); it != mlmp.rend(); ++it){
			out << it->second << " " << it->first << std::endl;
		}

		out.close();
	}
};

