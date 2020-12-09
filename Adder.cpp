#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"

using std::string;

class Adder {

	string memberA, memberB;
	int base;

public :
	static string add(string a, string b, int numberBase) {
		char* test = Converter::stringToCharArray(a);
		return "aaa";
	}
};
