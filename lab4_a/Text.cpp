#include "Text.h"

Text::Text() {
	not_double_code("");
}

Text::Text(std::string name) {
	not_double_code(name);
}

Text::Text(int size, std::string name){}
Text::Text(std::string name, int quantity){}
Text::Text(const Text& myObj){}
Text::Text(Text&& myObj){}

Text::~Text() { delete [] ptr; }


unsigned int Text::get_max_len()const { return 0; }
std::string Text::get_max_word()const{ return "qe"; }


void Text::not_double_code(std::string name){

	std::string str;
	if (name.empty()) str = "test_text.txt";
	else str = name;

	std::ifstream filein(str);
	if (!filein.is_open())
		std::cout << "Error" << std::endl;
	else std::cout << "File open"<<std::endl;

	std::string tmp;
	int counter = 0;
	while (filein >> tmp) {
		++counter;
	}
	size = counter;
	ptr = new std::string[size];

	filein.clear();
	filein.seekg(0);
	
	int i = 0;
	while (filein >> tmp) {
		ptr[i] = tmp;
		++i;
		std::cout << tmp << std::endl;
	}

	filein.close();
}