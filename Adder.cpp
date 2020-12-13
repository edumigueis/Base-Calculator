#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"
#include "NumberFormatter.cpp"

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
				numberB = NumberFormatter::completeWithZerosLeft(numberB, numberA.size());
			else
				numberA = NumberFormatter::completeWithZerosLeft(numberA, numberB.size());
		}
		else {
			if (commaA >= numberA.size())
				numberA = NumberFormatter::addComma(numberA, numberB.size() - commaB);
			else
				if (commaB >= numberB.size())
					numberB = NumberFormatter::addComma(numberB, numberA.size() - commaA);
				else {
					if (numberA.size() - commaA < numberB.size() - commaB) {
						numberA = NumberFormatter::completeWithZerosRight(numberA, numberB.size() - (commaB + 1), commaA);
					}
					else
						numberB = NumberFormatter::completeWithZerosRight(numberB, numberA.size() - (commaA + 1), commaB);
				}
			if (commaA > commaB)
				numberB = NumberFormatter::completeWithZerosLeft(numberB, numberA.size());
			else
				numberA = NumberFormatter::completeWithZerosLeft(numberA, numberB.size());
		}

		string res;
		bool addOne = false;
		for (int i = numberA.size() - 1; i >= -1; i--) {
			if (i == -1 && addOne == true) {
				res += "1";
				break;
			}
			else if (i == -1 && addOne == false)
				break;
			if (numberA[i] != ',') {
				int added = Converter::convertCharToInt(numberA[i]) + Converter::convertCharToInt(numberB[i]);
				if (added >= numberBase) {
					if (!addOne)
						added = (added - numberBase);
					else
						added = (added - numberBase) + 1;

					addOne = true;
					res += Converter::convertIntToChar(added);
					continue;
				}
				if (addOne == true) {
					added += 1;
					if (added >= numberBase) {
						added = (added - numberBase);
						res += Converter::convertIntToChar(added);
						continue;
					}
					addOne = false;
				}
				res += Converter::convertIntToChar(added);
			}
			else
				res += ",";
		}

		std::reverse(res.begin(), res.end());

		return res;
	}
};
