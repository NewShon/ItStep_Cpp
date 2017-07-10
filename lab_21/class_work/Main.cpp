#include <iostream>
using std::cout;
using std::endl;

#define print(el) cout << el << endl;

namespace lol {
	const int nnn = 999;
	void f() { print(nnn); }
}
namespace kek {
	const int ft = 42;
	void f() { lol::f(); }
} 

namespace k = kek;

namespace chebyrek {
	using namespace lol;
	using k::ft;
}


namespace qw{
	int x = 2;
	void ff();
	namespace ns {
		void func() {
			cout << "In In" << endl;
			ff();
		}
	}
	void ff() { 
		cout << "No name" << endl; 
		ns::func();
	}


}




int x = 1;

int main() {
	/*using namespace chebyrek;

	print(ft);
	int x = 15;
	print(::x);
	f();
	qw::ff();
	print(x);*/

	const int x = 100;
	const int* px = &x;
	int* tmp = const_cast<int*>(px);
	*tmp = 200;
	print(x);
	print(*tmp);
	return 0;
} 