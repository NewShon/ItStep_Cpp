#pragma once
#include <string>
#include <iostream>

class Person
{
	std::string mobile_phone;
	std::string home_phone;

public:
	std::string fio;

	Person();
	Person(std::string);
	Person(std::string, std::string);
	Person(std::string, std::string, std::string);

	void showINFO();

	~Person();
};

