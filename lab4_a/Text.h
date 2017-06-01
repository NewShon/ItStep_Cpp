#pragma once
#include <string>
#include<iostream>
#include <fstream>
class Text
{
	std::string* ptr;
	size_t size;
	unsigned int max_len{ 0 };
	std::string max_word;

	void not_double_code(std::string, int);

public:
	Text();
	Text(int);
	Text(std::string);
	Text(int, std::string);
	Text(const Text&);
	Text(Text&&);
	~Text();

	unsigned int get_max_len()const;
	std::string get_max_word()const;


};

