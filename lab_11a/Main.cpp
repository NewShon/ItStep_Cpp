#include <iostream>
#include "Pair.h"
#include <array>


template<typename T, typename ... Types>
void myPrint(const T head, Types ... args)
{
	std::cout << head << " ";
	myPrint(args...);
}

template<typename T>
void myPrint(const T head)
{
	std::cout << head;
	std::cout << std::endl;
}

void myPrint()
{
	std::cout << std::endl;
}


template<typename T, typename ... Args>
void myPrintf(const char* str, T first_a, Args ... args) {
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '%')
		{
			std::cout << first_a;
			myPrintf(str + i + 1, args...);
			break;
		}
		else std::cout << str[i];
	}
}
template<typename T>
void myPrintf(const char* str, T first_a) {
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '%') std::cout << first_a;
		else std::cout << str[i];
	}
}


void f() {
	myPrint(); 
	myPrint(1); 
	myPrint(10, 34, 45.12, 99.1189);
	myPrint(10, 34, 45.12, "text", "new string");
	myPrint("Student", 17, 2017, "18-11S", 9.1);
}

void f2() {
	myPrintf("Hello, %!", "world"); 
	std::cout << std::endl;
	myPrintf("Tel: % - % - %", 279, 13, 54);
	std::cout << std::endl;
	myPrintf("User: %\n Surname: %\n Age: %\n Score: %\n", "MyName", "MySurname", 25, 15.119);
	std::cout << std::endl;
}

int main() {

	f2();

	return 0;
}