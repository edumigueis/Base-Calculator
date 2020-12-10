#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"

using std::string;

class Subtractor {

	string memberA, memberB;
	int base;

public:
	static string subtract(string a, string b, int numberBase) {
		return "0";
	}
};