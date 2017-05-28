#pragma once
#define _USE_MATH_DEFINES
#include<iostream>
#include <cmath>
class Area
{
	static int counter;
	float a;
	float b;
	float angle;
public:
	Area(float a_) :a(a_), b(0), angle(0) {}
	Area(float a_, float b_) :a(a_), b(b_), angle(0) {}
	Area(float a_, float b_, float angle_) :a(a_), b(b_), angle(angle_){}

	void getSquareArea()const;
	void getParallelogramArea()const;
	void getRhombusArea()const;

	static int getCount();

	~Area();

private:
	float square1()const;
	float square2()const;

	float Parallelogram1()const;
	float Parallelogram2()const;

	float Rhombus1()const;
	float Rhombus2()const;
};

