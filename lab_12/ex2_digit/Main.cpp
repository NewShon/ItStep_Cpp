#include <fstream>
#include <iostream>

int main(){

	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	char tmp[256];
	int dig[50];

	while (in.getline(tmp, 256))
	{
		size_t j = 0;
		for (size_t i = 0; i < strlen(tmp); ++i)
		{
			if (isdigit(tmp[i]))
				dig[j++] = tmp[i];
			else out.put(tmp[i]);
		}
		for (size_t i = 0; i < j; ++i)
			out.put(dig[i]);
		out.put('\n');
	}

	return 0;
}