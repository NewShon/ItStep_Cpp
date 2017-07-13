#pragma once
#include "Novo_Parallelogram.h"

class Novo_Rectangle : public Novo_Parallelogram
{
	double side1;
	double side2;
public:
	Novo_Rectangle(double s1, double s2) :
		Novo_Parallelogram(s1, s2, 90), side1(s1), side2(s2) 
		{
		if (side1 < 0 || side2 < 0) {
			side1 = 0;
			side2 = 0;
		}
	}
	~Novo_Rectangle() {}

	double getArea() {
		return side1*side2;
	}

	double get_side1() const { return side1; }
	double get_side2() const { return side2; }
	
};

