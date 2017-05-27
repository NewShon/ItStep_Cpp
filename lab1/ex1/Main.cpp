#include <iostream>
#include "Student.h"

int main() {
	Student st1("Novokshonov Kirill", "31.03.1997");
	st1.set_Univer("BSU");

	Student st2("Black desert", "01.01.1996");
	st2.set_Univer("BSD");


	st1.get_FIO();
	st1.get_BD();
	st1.get_Univer();

	std::cout << std::endl;

	st2.get_FIO();
	st2.get_BD();
	st2.get_Univer();

	return 0;
}
