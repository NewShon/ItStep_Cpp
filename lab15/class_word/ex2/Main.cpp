#include <iostream>
#include <set>
#include <fstream>

int main() {

	std::multiset<int> in_ms;
	std::ifstream in("input.txt");

	int num;
	while (in >> num) {
		in_ms.insert(num);
	}

	in.close();
	in.clear();

	in.open("test.txt");
	std::ofstream out("output2.txt");
	while (in >> num) {
		out << num << " " << in_ms.count(num) << std::endl;
	}

	in.close();
	in.clear();

	return 0;
}
