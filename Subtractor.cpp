#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"
#include "NumberFormatter.cpp"

using std::string;

class Subtractor {

	string memberA, memberB;
	int base;

public:
	static string subtract(string a, string b, int numberBase) {
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
		for (int i = numberA.size() - 1; i >= -1; i--) {
			if (numberA[i] != ',') {
				int sub = Converter::convertCharToInt(numberA[i]) + Converter::convertCharToInt(numberB[i]);
				if (sub < 0) {
					int a = i;
					bool enough;
					while (!enough) { //in case there are zeros in the number
						a--;
						int current = Converter::convertCharToInt(numberA[a]);
						if (current > 0) {
							numberA[a] = Converter::convertIntToChar(current--); //aqui tem q salvar na posição do current o current-- e adicionar a valor da base no sub
							sub += numberBase;
							enough = true;
						}
					}
					//borrow base value from next iteration
				}
				res += Converter::convertIntToChar(sub);
			}
			else
				res += ",";
		}

		std::reverse(res.begin(), res.end());

		return res;
	}
};