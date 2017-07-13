#define _USE_MATH_DEFINES
#include "Novo_Parallelogram.h"
#include <cmath>


Novo_Parallelogram::Novo_Parallelogram(double s1, double s2, double a1) :
	side1(s1), side2(s2), angle1(a1)
{
	if (angle1 > 180 || angle1 < 0 ||
		side1 < 0 || side2 < 0) {

		side1 = 0;
		side2 = 0;
		angle1 = 0;
	}
}

double Novo_Parallelogram::getArea() {
	return side1 * side2 * std::sin(angle1*M_PI / 180);
}

Novo_Parallelogram::~Novo_Parallelogram()
{
}
