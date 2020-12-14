#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"
#include "NumberFormatter.cpp"
#include "Adder.cpp"

using std::string;

class Multiplier {
private:
	vector<char> numberA, numberB;
	int base;
	int finalCommaIndex = 0;

	void countCommas() {
		auto it = find(numberA.begin(), numberA.end(), ',');
		int commaA = std::distance(numberA.begin(), it);
		auto itB = find(numberB.begin(), numberB.end(), ',');
		int commaB = std::distance(numberB.begin(), itB);

		if (commaA < numberA.size())
			finalCommaIndex += (numberA.size() - commaA - 1);
		if (commaB < numberB.size())
			finalCommaIndex += (numberB.size() - commaB - 1);
	}
public:
	Multiplier(string numberA, string numberB, int numberBase) {
		this->numberA = Converter::stringToCharArray(numberA);
		this->numberB = Converter::stringToCharArray(numberB);
		this->base = numberBase;
	}

	void setNumberA(string numberA) {
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

	string multiply() {
		countCommas();

		string res;
		vector<string> partRes;
		int toBeAdded;
		int zeroCount = 0;
		for (int a = numberB.size() - 1; a >= 0; a--) {
			res = "";
			if (numberB[a] != ',') {
				toBeAdded = -1;
				for (int i = numberA.size() - 1; i >= 0; i--) {
					if (numberA[i] != ',') {
						int mult = Converter::convertCharToInt(numberA[i]) * Converter::convertCharToInt(numberB[a]);
						if (toBeAdded > 0) {
							mult += toBeAdded;
							toBeAdded = -1;
						}
						if (mult > base) {
							int remainder = mult % base;
							toBeAdded = (mult - remainder) / base;
							mult = remainder;
						}
						if (i == 0) {
							res += Converter::convertIntToChar(mult);
							if(toBeAdded > 0)
							res += Converter::convertIntToChar(toBeAdded);
							break;
						}
						res += Converter::convertIntToChar(mult);
					}
				}
				std::reverse(res.begin(), res.end());
				for (int z = 0; z < zeroCount; z++)
					res += "0";
				partRes.push_back(res);
				zeroCount++;
			}
		}

		string mainRes = "0";
		Adder adder(mainRes, "0", base);
		for (int b = 0; b < partRes.size(); b++) {
			adder.setNumberA(mainRes);
			adder.setNumberB(partRes[b]);
			mainRes = adder.add();
		}

		if(finalCommaIndex > 0)
			mainRes = NumberFormatter::addCommaAt(mainRes, (mainRes.size() - finalCommaIndex));

		return mainRes;
	}
};