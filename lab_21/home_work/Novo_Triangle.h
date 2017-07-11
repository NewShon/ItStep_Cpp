#pragma once
#include "Novo_Shape.h"
#include <algorithm>

class Novo_Triangle : public Shape
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


	void set_side1(double s) { side1 = s; }
	void set_side2(double s) { side1 = s; }
	void set_side3(double s) { side1 = s; }

	void set_angle1(double a) { angle1 = a; }
	void set_angle2(double a) { angle2 = a; }
	void set_angle3(double a) { angle3 = a; }


	double getArea();


private:
	double SSS();
	double SSU();
	double SUU();

};

