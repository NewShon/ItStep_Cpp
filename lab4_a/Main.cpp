#include "Text.h"

int main()
{
	setlocale(0, "");
	Text t;
	Text t1(20);
	Text t2("text1.txt");
	Text t3(100, "text2.txt");
	Text t4(t3);
	Text t5 = std::move(t2);

	std::cout << t4.get_max_len() << std::endl;
	std::cout << t4.get_max_word() << std::endl;
	std::cout << t5.get_max_len() << std::endl;
	std::cout << t5.get_max_word() << std::endl;
	
	return 0;
}