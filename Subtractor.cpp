#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include "Converter.cpp"
#include "NumberFormatter.cpp"

using std::string;

class Subtractor {
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
	Subtractor(string numberA, string numberB, int numberBase) {
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

	string subtract() {
		formatNumbers();
		string res;
		bool isNegative = false;
		for (int i2 = 0; i2 < numberA.size(); i2++) { // corrigir essa parte no caso 90 - 5
			if (Converter::convertCharToInt(numberA[i2]) < Converter::convertCharToInt(numberB[i2])) {
				isNegative = true;
				vector<char> aux(numberB.size());
				for (int i3 = 0; i3 < numberB.size(); i3++) {
					aux[i3] = numberB[i3];
				}
				numberB = numberA;
				numberA = aux;
				break;
			}
		}

		for (int i = numberA.size() - 1; i > -1; i--) {
			if (numberA[i] != ',') {
				int sub = Converter::convertCharToInt(numberA[i]) - Converter::convertCharToInt(numberB[i]);
				if (sub < 0) {
					int a = i;
					bool enough = false;
					bool positiveFound = false;
					while (!enough) { //in case there are zeros in the number
						if (!positiveFound)
							a--;
						else
							a++;
						int current = Converter::convertCharToInt(numberA[a]);
						if (current > 0) {
							current--;
							numberA[a] = Converter::convertIntToChar(current); //aqui tem q salvar na posição do current o current-- e adicionar a valor da base no sub
							numberA[a + 1] = Converter::convertIntToChar(Converter::convertCharToInt(numberA[a + 1]) + base);
							positiveFound = true;
						}
						if (a == i - 1 && positiveFound == true)
							enough = true;
					}
					//borrow base value from next iteration
					sub = Converter::convertCharToInt(numberA[i]) - Converter::convertCharToInt(numberB[i]);
				}
				if (sub >= 0)
					res += Converter::convertIntToChar(sub);
				else
				if(sub < 0 && i <=0)
					res += std::to_string(sub *-1);
			}
			else
				res += ",";
		}

		std::reverse(res.begin(), res.end());

		if (isNegative == true)
			res = NumberFormatter::addMinusSign(res);

		return res;
	}
};