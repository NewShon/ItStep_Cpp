#include <iostream>
#include "Helper.h"
using std::cout;
using std::endl;

int main(){
	setlocale(0, "");

	CrosswordSolver h;
	h.getAllWithLen(3);
	h.getAllWithInit('ё');
	h.findByMask("*с?д?");
	h.getAnagrams("донор");

	return 0;
}