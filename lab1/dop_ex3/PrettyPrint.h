#pragma once
#include <string>
class PrettyPrint
{
public:
	PrettyPrint() {}
	~PrettyPrint() {}

	std::string getConcatination(std::string, std::string);
	void replace(std::string &);
	void reverse(std::string &);
};

