#include "PrettyPrint.h"

std::string PrettyPrint::getConcatination(std::string str1, std::string str2){
	return (str1 + "." + str2);
}
void PrettyPrint::replace(std::string & str){
	for (int i = 0; i < str.length(); ++i)
		if (str[i] == 'a') str[i] = 'o';
}
void PrettyPrint::reverse(std::string & str){
	std::string tmp = str;
	for (int i = str.length() - 1, j = 0; i >= 0; --i, ++j)
		str[j] = tmp[i];
}
