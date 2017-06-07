#include <iostream>
#include "PrettyPrint.h"

int main(){

	PrettyPrint pp;
	std::string str = "Hafanana";

	std::cout << pp.getConcatination("Hello", str) << std::endl;

	pp.replace(str);
	std::cout << str << std::endl;

	pp.reverse(str);
	std::cout << str << std::endl;

	return 0;
}