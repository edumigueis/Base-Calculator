/*
Authors: Eduardo Migueis and Rodrigo Smith.
Repository: https://github.com/edumigueis/Base-Calculator
License: MIT License.
*/
#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include <vector>

using std::string;
using std::vector;

class NumberFormatter {
public:
	static string removeMinusSign(string toBeChanged) throw (std::invalid_argument) {
		if(toBeChanged.length() <= 0)
			throw std::invalid_argument("A valid string must be provided.");

		string res;
		if (toBeChanged.find('-') == std::string::npos)
			return toBeChanged;
		else {
			res = toBeChanged;
		}
			return res.erase(0, 1);
	};

	static string addMinusSign(string toAdd) {
		string res;
		res.resize(toAdd.length() + 1);
		res[0] = '-';
		for (int i = 1; i < toAdd.length() + 1; i++)
			res[i] = toAdd[i - 1];
		return res;
	};

	static vector<char> addComma(vector<char> toBeChanged, int commaSize) throw (std::invalid_argument) {
		if (commaSize < 0)
			throw std::invalid_argument("The number of zeros after comma must be positive.");

		vector<char> res(toBeChanged.size() + commaSize);
		for (int i = 0; i < toBeChanged.size(); i++)
			res[i] = toBeChanged[i];
		res[toBeChanged.size()] = ',';
		for (int b = toBeChanged.size() + 1; b < toBeChanged.size() + commaSize; b++)
			res[b] = '0';
		return res;
	}

	static string addCommaAt(string toAdd, int index) throw (std::invalid_argument) {
		if (index < 0)
			throw std::invalid_argument("Index must be positive.");

		string res;
		res.resize(toAdd.length() + 1);
		res[index] = ',';
		int i2 = 0;
		for (int i = 0; i < res.length(); i++) {
			if (res[i] == ',') 
				continue;
			res[i] = toAdd[i2];
			i2++;
		}
		return res;
	}

	static vector<char> completeWithZerosRight(vector<char> toBeChanged, int commaSize, int commaIndex) throw (std::invalid_argument)  {
		if (commaIndex < 0 || commaIndex > toBeChanged.size())
			throw std::invalid_argument("Index of comma must be positive and inside vector range.");

		vector<char> res(commaIndex + commaSize + 1);
		for (int i = 0; i < toBeChanged.size(); i++)
			res[i] = toBeChanged[i];
		if (commaSize > 0)
		{
			for (int b = toBeChanged.size(); b <= commaIndex + commaSize; b++)
				res[b] = '0';
		}
		return res;
	}

	static vector<char> completeWithZerosLeft(vector<char> toBeChanged, int finalSize) throw (std::invalid_argument) {
		if(finalSize < 0)
			throw std::invalid_argument("Final size must be positive.");

		vector<char> res(finalSize);
		int a = toBeChanged.size() - 1;
		for (int i = finalSize - 1; i >= 0; i--) {
			if (finalSize - i <= toBeChanged.size())
				res[i] = toBeChanged[a];
			else
				res[i] = '0';

			a--;
		}
		return res;
	}
};