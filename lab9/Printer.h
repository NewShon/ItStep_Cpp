#pragma once
#include <string>
#include <fstream>
class Printer
{
	std::string model;
	size_t year;
	std::string manufacturer;
	size_t this_doc_counter{ 0 };
	static size_t all_doc_counter;
public:
	Printer(std::string mod, size_t yr, std::string manuf) :
		model(mod), year(yr), manufacturer(manuf) {}
	
	void printCopy(std::string, std::string to = "output.txt");
	void printCharsWithStep(std::string, size_t);
	void printWordWithStep(std::string, size_t);
	void printReverse(std::string);
	void printConcordance(std::string, std::string);

	bool check(std::string);
	
	size_t getThisCounter() const {
		return this_doc_counter;
	}
	static size_t getAllCounter() const {
		return all_doc_counter;
	}
};

