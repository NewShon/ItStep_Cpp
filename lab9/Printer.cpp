#include "Printer.h"
#include <iostream>

size_t Printer::all_doc_counter = 0;

void Printer::printCopy(std::string from, std::string to){
	std::ifstream in(from);
	std::ofstream out(to);
	
	if (!check(from)) return;
	if (!check(to)) return;

	char tmp[256];
	while (in.getline(tmp, 256))
		out << tmp << "\n";
	
	in.close();
	out.close();

	++this_doc_counter;
	++all_doc_counter;
}
void Printer::printCharsWithStep(std::string file_name, size_t n_symb){
	std::ifstream in(file_name);
	if (!check(file_name)) return;

	char tmp[256];
	while (in.getline(tmp,256))
	{
		for (size_t i = 0; i < strlen(tmp); i += n_symb)
			std::cout << tmp[i] << " ";
		std::cout << std::endl;
	}

	in.close();

	++this_doc_counter;
	++all_doc_counter;
}
void Printer::printWordWithStep(std::string file_name, size_t n_word){
	std::ifstream in(file_name);
	if (!check(file_name)) return;

	std::string tmp;
	size_t counter = 0;
	while (in >> tmp)
	{
		if (counter % n_word == 0) std::cout << tmp << " ";
		++counter;
	}

	in.close();

	++this_doc_counter;
	++all_doc_counter;
}
void Printer::printReverse(std::string file_name){
	std::ifstream in(file_name);
	if (!check(file_name)) return;

	int id = 0;
	char tmp[1];
	while (in.seekg(--id, std::ios_base::end)){
		in.read(tmp, 1);
		std::cout << tmp[0];
	}

	in.close();

	++this_doc_counter;
	++all_doc_counter;
}
void Printer::printConcordance(std::string word, std::string file_name){
	std::ifstream in(file_name);
	if (!check(file_name)) return;


	size_t size = 0;
	std::string tmp;
	bool flag = 0;
	while (in >> tmp){
		++size;
		if (word == tmp) {
			flag = 1;
			break;
		}
	}

	if (!flag) std::cout << "Not found";


	std::string* arr = new std::string[size+3];
	//in.clear();
	in.seekg(0);


	size_t i = 0;
	while (in >> arr[i++] && (i <(size + 3)));

	
	size_t j = 0;
	if (size > 3) j = size - 4;
	for (; (j < (size + 3)) && (j < i); ++j)
		std::cout << arr[j] << " ";

	in.close();

	++this_doc_counter;
	++all_doc_counter;
}


bool Printer::check(std::string file_name){
	std::ifstream in(file_name);
	if (!(in.is_open()))
	{
		std::cout << "File Error" << std::endl;
		in.close();
		return 0;
	}
	in.close();
	return 1;
}