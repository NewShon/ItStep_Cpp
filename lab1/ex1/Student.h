#pragma once
#include <iostream>
#include <string>

class Student
{
	std::string fio;
	const std::string bd;
	std::string phone;
	std::string city;
	std::string university;
	std::string id_group;

public:
	Student(std::string name, std::string birth);

	void set_FIO(std::string);
	//void set_BD(std::string);
	void set_Phone(std::string);
	void set_City(std::string);
	void set_Univer(std::string);
	void set_ID_group(std::string);


	void get_FIO()const;
	void get_BD()const;
	void get_Phone()const;
	void get_City()const;
	void get_Univer()const;
	void get_ID_group()const;


	~Student();
};

