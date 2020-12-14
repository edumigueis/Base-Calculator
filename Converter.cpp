#pragma once
#include <iostream>
#include<string>
#include <stdlib.h>
#include <vector>

using std::string;
using std::vector;

class Converter {
public:
    static vector<char> stringToCharArray(string toConvert) {
        if (toConvert.length() <= 0)
            return vector<char>();
        else {
            vector<char> res(toConvert.length());
            for (int i = 0; i < toConvert.length(); i++)
                res[i] = toConvert[i];
            return res;
        }
    };
    static string charArrayToString(vector<char> toConvert) {
        if (toConvert.size() <= 0)
            return "";
        else {
            string res;
            for (int i = 0; i < toConvert.size(); i++)
                res += toConvert[i];
            return res;
        }
    }
	static int convertCharToInt(char toBeConverted) {
        char c = toupper(toBeConverted);
		vector<char> alpha = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'J',
        'K',
        'L',
        'M',
        'N',
        'O',
        'P',
        'Q',
        'R',
        'S',
        'T',
        'U',
        'V',
        'W',
        'X',
        'Y',
        'Z'
        };
        auto it = find(alpha.begin(), alpha.end(), c);
        int index = std::distance(alpha.begin(), it);
        return index;
	}

    static char convertIntToChar(int number) {
        if(number < 0 || number > 36)
            throw std::invalid_argument("A negative number or a number bigger than 36 can't be converted to an alphanumeric representation.");

        vector<char> alpha = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'J',
        'K',
        'L',
        'M',
        'N',
        'O',
        'P',
        'Q',
        'R',
        'S',
        'T',
        'U',
        'V',
        'W',
        'X',
        'Y',
        'Z'
        };
        return alpha[number];
    }
};