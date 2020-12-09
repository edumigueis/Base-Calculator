#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"

using std::string;

class Adder {

	string memberA, memberB;
	int base;

public:
	static string add(string a, string b, int numberBase) {
		vector<char> numberA = Converter::stringToCharArray(a);
		vector<char> numberB = Converter::stringToCharArray(b);

		auto it = find(numberA.begin(), numberA.end(), ',');
		int commaA = std::distance(numberA.begin(), it);
		auto itB = find(numberB.begin(), numberB.end(), ',');
		int commaB = std::distance(numberB.begin(), itB);

		if (commaA >= numberA.size() && commaB >= numberB.size()) {
			if (commaA > commaB)
				numberB = Converter::completeWithZerosLeft(numberB, numberA.size());
			else
				numberA = Converter::completeWithZerosLeft(numberA, numberB.size());
		}
		else {
			if (commaA >= numberA.size())
				numberA = Converter::addComma(numberA, numberB.size() - commaB);
			else
				if (commaB >= numberB.size())
					numberB = Converter::addComma(numberB, numberA.size() - commaA);
				else {
					if (numberA.size() - commaA < numberB.size() - commaB) {
						numberA = Converter::completeWithZerosRight(numberA, numberB.size());
					}
					else
						numberB = Converter::completeWithZerosRight(numberB, numberA.size());
				}
			if (commaA > commaB)
				numberB = Converter::completeWithZerosLeft(numberB, numberA.size());
			else
				numberA = Converter::completeWithZerosLeft(numberA, numberB.size());
		}

		for (int i = numberA.size() - 1; i > 0; i--) {
			if (Converter::convertCharToInt(numberA[i]) + Converter::convertCharToInt(numberB[i]))
				return "bbbb";
		}

		return "aaa";
	}
};
