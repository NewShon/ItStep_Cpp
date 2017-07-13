#pragma once
#include "Novo_Rectangle.h"

class Novo_Square : public Novo_Rectangle
{
	double side1;
public:
	Novo_Square(double s1) :
		Novo_Rectangle(s1, s1), side1(s1){
		if (side1 < 0) {
			side1 = 0;
		}
	}
	~Novo_Square() {}

	double getArea() {
		return side1*side1;
	}

	double get_side1() const { return side1; }

};
