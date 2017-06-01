#include "Text.h"

//1
Text::Text() {
	not_double_code("", 0);
}
//2
Text::Text(int size) {
	not_double_code("",size);
}
//3
Text::Text(std::string name) {
	not_double_code(name, 0);
}
//4
Text::Text(int size, std::string name){
	not_double_code(name, size);
}
//5
Text::Text(const Text& myObj){
	ptr = new std::string[myObj.size];
	max_len = myObj.max_len;
	max_word = myObj.max_word;
	for (unsigned int i = 0; i < size; ++i)
	{
		ptr[i] = myObj.ptr[i];
	}
	std::cout << "Its a COPY!!!!" << std::endl;
}
//6
Text::Text(Text&& myObj) :size(myObj.size), ptr(myObj.ptr), max_len(myObj.max_len), max_word(myObj.max_word)
{
	myObj.size = 0;
	myObj.ptr = nullptr;
	myObj.max_len = 0;
	myObj.max_word = "";
	std::cout << "Its a MOVE!!!!" << std::endl;
}

Text::~Text() { delete [] ptr; }


unsigned int Text::get_max_len()const { return this->max_len; }
std::string Text::get_max_word()const{ return this->max_word; }


void Text::not_double_code(std::string name, int s){

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
	this->size = counter;
	ptr = new std::string[size];

	filein.clear();
	filein.seekg(0);
	
	int len;
	if (s == 0) len = this->size;
	else len = s;
	for (int i = 0; i < len; ++i, filein >> tmp)
	{
		if (tmp.length() > max_len)
		{
			max_len = tmp.length();
			max_word = tmp;
		}
		ptr[i] = tmp;
	}

		
	std::cout << max_len << std::endl;
	std::cout << max_word << std::endl;

	filein.close();
}