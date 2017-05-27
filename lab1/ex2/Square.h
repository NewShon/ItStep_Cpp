#pragma once
#include <iostream>
class Square
{
	float a;
	float b;
public:
	Square(float);
	Square(float, float);

	float getA()const;
	float getB()const;

	void setA(float);
	void setB(float);

	void getSquareArea()const;

	~Square();

private:
	float getAA()const;
	float getAB()const;
};

