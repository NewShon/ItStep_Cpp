#include "Triangle.h"
#include "Square.h"
int main(){

	Triangle t(4,4);
	t.getTriangleArea();

	Triangle t2(4, 4, 4);
	t2.getTriangleArea();

	Triangle t3(4, 4, 4, 1);
	t3.getTriangleArea();

	Square s(5);
	s.getSquareArea();

	Square s2(5,3);
	s2.getSquareArea();

	return 0;
}