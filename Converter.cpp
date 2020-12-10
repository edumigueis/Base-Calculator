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
        vector<char> res(toConvert.length());
        for (int i = 0; i < toConvert.length(); i++)
            res[i] = toConvert[i];
        return res;
    };
    static string charArrayToString(vector<char> toConvert) {
        string res;
        for (int i = 0; i < toConvert.size(); i++)
            res+= toConvert[i];
        return res;
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