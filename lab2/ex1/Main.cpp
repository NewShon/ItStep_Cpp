#include "Area.h"

int main(){

	Area a1(4.0), a2(3,7), a3(5,6);

	a1.getSquareArea();
	a2.getParallelogramArea();
	a3.getRhombusArea();

	Area::getCount();

	return 0;
}