#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include <vector>

using std::string;
using std::vector;

class NumberFormatter {
public:
	static string removeMinusSign(string toBeChanged) {
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
	static vector<char> addComma(vector<char> toBeChanged, int commaSize) {
		vector<char> res(toBeChanged.size() + commaSize);
		for (int i = 0; i < toBeChanged.size(); i++)
			res[i] = toBeChanged[i];
		res[toBeChanged.size()] = ',';
		if (commaSize > 0)
		{
			for (int b = toBeChanged.size() + 1; b < toBeChanged.size() + commaSize; b++)
				res[b] = '0';
		}
		return res;
	}
	static vector<char> completeWithZerosRight(vector<char> toBeChanged, int commaSize, int commaIndex) {
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
	static vector<char> completeWithZerosLeft(vector<char> toBeChanged, int finalSize) {
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