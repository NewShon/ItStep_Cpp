#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

int main() {

	std::ifstream in("turgenev.txt");
	if (!in.is_open()) return 1;


	std::list<std::string> myList;
	std::string tmp;
	while (in >> tmp) {
		myList.push_back(tmp);
	}


	std::ofstream out("turgenev_output.txt");
	out << "Words:\t" << myList.size();


	myList.sort();
	myList.unique();
	

	std::list<std::string> myUniqList;
	for (std::string word : myList)
		if (word.size() == 7) {
			myUniqList.push_back(word);
		}


	out << "\nUnique words:\t" << myUniqList.size();


	std::list<std::string> Inf;
	for (std::string word : myUniqList) {
		std::string tmp = word.substr(5, 2);
		if (tmp == "��" || tmp == "��" || tmp == "��")
			Inf.push_back(word);
	}
		
	

	out << "\nInf words:\t" << Inf.size();
	out << "\n";


	for (const auto& word : Inf)
		out << word << " ";

	Inf.pop_front();
	Inf.pop_front();

	int i = 1;
	for (auto it = Inf.begin(); it != Inf.end(); ++i)
	{
		if (i == 9 || i == 17 ||
			i == 35 || i == 40 || i == 41 || i == 42 ||
			i == 46 || i == 51) {
			Inf.erase(it++);
		}
		else ++it;
	}
	out << "\nInf words:\t" << Inf.size();


	auto it = Inf.begin();
	while (it != Inf.end()) {
		std::string tmp = (*it).substr(0, 3);
		if (tmp == "���" || tmp == "���" || tmp == "���" || tmp == "���" || tmp == "���")
			Inf.erase(it++);
		++it;
	}


	out << "\nInf words:\t" << Inf.size();

	Inf.remove("�������");
	Inf.remove("�������");
	Inf.remove("�������");


	out << "\nInf words:\t" << Inf.size();


	Inf.push_front("�����");
	Inf.push_back("�����");
	


	for (auto it = Inf.begin(); it != Inf.end(); ++it)
		if (*it == "�������") {
			Inf.insert(it, "������");
			break;
		}


	out << "\n";
	for (auto word : Inf)
		out << word << " ";

	out << "\nInf words:\t" << Inf.size();


	in.close();
	out.close();
	return 0;
}