#include <iostream>
#include "Helper.h"
using std::cout;
using std::endl;

int main(){
	setlocale(0, "");

	CrosswordSolver h;
	h.getAllWithLen(3);
	h.getAllWithInit('�');
	h.findByMask("*�?�?");
	h.getAnagrams("�����");

	return 0;
}