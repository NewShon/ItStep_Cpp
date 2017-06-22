#include <iostream>
#include <set>
#include <fstream>

int main() {

	std::set<int> in_s;
	
	std::ifstream in("input.txt");

	int num;
	while (in >> num) {
		in_s.insert(num);
	}

	in.close();
	in.clear();

	in.open("test.txt");
	std::ofstream out("output.txt");
	while (in >> num) {
		if (in_s.find(num) != in_s.end()) {
			out << "Yes\n";
		}
		else {
			out << "No\n";
		}
	}
	in.close();
	in.clear();
  
  return 0;
  
  }
