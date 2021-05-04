/*
Authors: Eduardo Migueis and Rodrigo Smith.
Repository: https://github.com/edumigueis/Base-Calculator
License: MIT License.
*/
#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"
#include "NumberFormatter.cpp"

using std::string;

class Adder {

private:
	vector<char> numberA, numberB;
	int base;

	void formatNumbers() {
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
	}

public:
	Adder(string numberA, string numberB, int numberBase) {
		this->numberA = Converter::stringToCharArray(numberA);
		this->numberB = Converter::stringToCharArray(numberB);
		this->base = numberBase;
	};

	void setNumberA(string numberA){
		this->numberA = Converter::stringToCharArray(numberA);
	}

	void setNumberB(string numberB) {
		this->numberB = Converter::stringToCharArray(numberB);
	}

	string getNumberA() {
		return Converter::charArrayToString(this->numberA);
	}

	string getNumberB() {
		return Converter::charArrayToString(this->numberB);
	}

	void setBase(int nBase) {
		if(nBase > 0 && nBase < 37)
		this->base = nBase;
	}

	string add() {
		formatNumbers();
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
				if (added >= base) {
					if (!addOne)
						added = (added - base);
					else
						added = (added - base) + 1;

					addOne = true;
					res += Converter::convertIntToChar(added);
					continue;
				}
				if (addOne == true) {
					added += 1;
					if (added >= base) {
						added = (added - base);
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
