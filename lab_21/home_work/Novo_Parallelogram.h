#pragma once
#include "Novo_Shape.h"

class Novo_Parallelogram : public Novo_Shape
{
	double side1;
	double side2;
	
	double angle1;
public:
	Novo_Parallelogram(double, double, double);
	~Novo_Parallelogram();

	double get_side1() const { return side1; }
	double get_side2() const { return side2; }

	double get_angle1() const { return angle1; }

	double getArea();
};

