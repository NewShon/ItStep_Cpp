#pragma once
#include <string>
#include <unordered_map>

class CrosswordSolver
{
	std::unordered_map<std::string, std::string> map_dictionary;

public:
	CrosswordSolver() { readDocument("Lopatin_dictionary.txt"); }
	CrosswordSolver(std::string doc_name) { readDocument(doc_name); }
	~CrosswordSolver() {}

	void readDocument(std::string);

	void getAllWithLen(size_t);
	void getAllWithInit(char);
	void findByMask(std::string);
	void getAnagrams(std::string);


};

