#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"
#include "NumberFormatter.cpp"
#include "Adder.cpp"

using std::string;

class Multiplier {

public:
	static string multiply(string a, string b, int numberBase) {
		vector<char> numberA = Converter::stringToCharArray(a);
		vector<char> numberB = Converter::stringToCharArray(b);

		auto it = find(numberA.begin(), numberA.end(), ',');
		int commaA = std::distance(numberA.begin(), it);
		auto itB = find(numberB.begin(), numberB.end(), ',');
		int commaB = std::distance(numberB.begin(), itB);
		int finalCommaIndex = 0;

		if (commaA < numberA.size())
			finalCommaIndex += (numberA.size() - commaA - 1);
		if(commaB < numberB.size())
			finalCommaIndex += (numberB.size() - commaB - 1);

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
						if (mult > numberBase) {
							int remainder = mult % numberBase;
							toBeAdded = (mult - remainder) / numberBase;
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
		for (int b = 0; b < partRes.size(); b++) {
			mainRes = Adder::add(mainRes, partRes[b], numberBase);
		}

		if(finalCommaIndex > 0)
			mainRes = NumberFormatter::addCommaAt(mainRes, (mainRes.size() - finalCommaIndex));

		return mainRes;
	}
};