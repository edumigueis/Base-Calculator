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
	}
    static vector<char> addComma(vector<char> toBeChanged, int commaSize) {
        vector<char> res(commaSize + 1);
        res[toBeChanged.size()] = ',';
        if (commaSize > 0)
        {
            for (int b = toBeChanged.size() + 1; b < commaSize; b++)
                res[b] = '0';
        }
        return res;
    }
    static vector<char> completeWithZerosRight(vector<char> toBeChanged, int commaSize) {
        vector<char> res(commaSize + 1);
        if (commaSize > 0)
        {
            for (int b = toBeChanged.size(); b < commaSize; b++)
                res[b] = '0';
        }
        return res;
    }
	static vector<char> completeWithZerosLeft(vector<char> toBeChanged, int finalSize) {
		vector<char> res(finalSize + 1);
        
        int a = toBeChanged.size() -1;
		for (int i = finalSize - 1; i > 0; i--) {
			if (finalSize - i < toBeChanged.size())
				res[i] = toBeChanged[a];
			else
				res[i] = '0';

            a--;
		}
		return res;
	}
	static int convertCharToInt(char toBeConverted) {
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
        auto it = find(alpha.begin(), alpha.end(), toBeConverted);
        int index = std::distance(alpha.begin(), it);
        return index;
	}
};