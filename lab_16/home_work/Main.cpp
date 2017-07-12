#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

template <typename T>
void print(T& v){
	for (auto& el : v){
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

template <typename T>
T init(T v){
	for (size_t i = 0; i < 20; ++i){
		v.push_back(rand() % 601 - 300);
	}
	return v;
}

class Pred{
	int data;
	int ex;
public:
	Pred(const int& d, int num) : data(d), ex(num) {}
	bool operator()(const int& el){
		if (ex == 1){
			return data == el;
		}
		if (ex == 2){
			return el % data == 0;
		}
		if (ex == 3){
			int tmp = abs(el);
			while (tmp > 9){
				tmp /= 10;
			}
			return tmp == data;
		}
		if (ex == 4){
			return (el >= 100 && el <= 999) || (el <= -100 && el >= -999);
		}
		if (ex == 5){
			return el == (data*data);
		}
	}
};

int main(){
	using namespace std;
	srand(time(0));

	vector<int> v;
	v = init(v);
	print(v);
	
	cout << endl;

	cout << "Ex1: find element" << endl;
	v.push_back(10);
	auto it = find_if(v.begin(), v.end(), Pred(10, 1));
	while (it != v.end()){
		if (it != v.end()){
			cout << *it << " ";
			it = find_if(++it, v.end(), Pred(10, 1));
		}
	}
	size_t counter = count_if(v.begin(), v.end(), Pred(10, 1));
	cout << "\nQuantity of elements: " << counter << endl;
	
	cout << endl;

	cout << "Ex2: find % n == 0" << endl;
	it = find_if(v.begin(), v.end(), Pred(3, 2));
	while (it != v.end()){
		if (it != v.end()){
			cout << *it << " ";
			it = find_if(++it, v.end(), Pred(3, 2));
		}
	}
	cout << endl;
	it = remove_if(v.begin(), v.end(), Pred(3, 2));
	v.erase(it, v.end());
	print(v);

	cout << endl << endl;

	cout << "Ex3: find first num == el" << endl;
	it = find_if(v.begin(), v.end(), Pred(2, 3));
	while (it != v.end()){
		if (it != v.end()){
			cout << *it << " ";
			it = find_if(++it, v.end(), Pred(2, 3));
		}
	}
	cout << endl;
	replace_if(v.begin(), v.end(), Pred(2, 3), 999);
	print(v);

	cout << endl;

	cout << "Ex4: find three-digit" << endl;
	it = find_if(v.begin(), v.end(), Pred(2, 4));
	while (it != v.end()){
		if (it != v.end()){
			cout << *it << " ";
			it = find_if(++it, v.end(), Pred(2, 4));
		}
	}

	cout << endl << endl;

	cout << "Ex5: find pow(n)" << endl;
	v.push_back(4);
	it = find_if(v.begin(), v.end(), Pred(2, 5));
	while (it != v.end()){
		if (it != v.end()){
			cout << *it << " ";
			it = find_if(++it, v.end(), Pred(2, 5));
		}
	}
	cout << endl;

	return 0;
}