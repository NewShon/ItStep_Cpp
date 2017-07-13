#pragma once
#include "Novo_Shape.h"
#include <algorithm>

class Novo_Triangle : public Novo_Shape
{
	double side1;
	double side2;
	double side3;

	double angle1;
	double angle2;
	double angle3;

	int find_formula;

public:
	Novo_Triangle(double, double, double);
	Novo_Triangle(std::pair<double,double>, double);
	Novo_Triangle(double, std::pair<double, double>);

	~Novo_Triangle();

	
	double get_side1() const { return side1; }
	double get_side2() const { return side2; }
	double get_side3() const { return side3; }

	double get_angle1() const { return angle1; }
	double get_angle2() const { return angle2; }
	double get_angle3() const { return angle3; }


	double getArea();


private:
	double get_Area_SideSideSide();
	double  get_Area_SideSideAngle();
	double  get_Area_SideAngleAngle();

	bool check();
	void allNULL();

};

