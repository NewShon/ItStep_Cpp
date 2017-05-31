#pragma once
#include <string>
#include<iostream>
#include <fstream>
class Text
{
	std::string* ptr;
	size_t size;

	void not_double_code(std::string);

public:
	Text();
	Text(std::string);
	Text(int, std::string);
	Text(std::string, int);
	Text(const Text&);
	Text(Text&&);
	~Text();

	unsigned int get_max_len()const;
	std::string get_max_word()const;


};

