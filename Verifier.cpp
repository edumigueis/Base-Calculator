#include <iostream>

#include<string>

#include <stdlib.h>

#include <algorithm>

#include <cctype>

using std::string;

class Verifier {
public:
	static bool verify(string a, string b, int numberBase) {
		string alpha[36] = {
		  "0",
		  "1",
		  "2",
		  "3",
		  "4",
		  "5",
		  "6",
		  "7",
		  "8",
		  "9",
		  "a",
		  "b",
		  "c",
		  "d",
		  "e",
		  "f",
		  "g",
		  "h",
		  "i",
		  "j",
		  "k",
		  "l",
		  "m",
		  "n",
		  "o",
		  "p",
		  "q",
		  "r",
		  "s",
		  "t",
		  "u",
		  "v",
		  "w",
		  "x",
		  "y",
		  "z"
		};
		if (a.empty() == true || b.empty() == true)
			return false;
		std::transform(a.begin(), a.end(), a.begin(),
			[](unsigned char c) {
				return std::tolower(c);
			});
		std::transform(b.begin(), b.end(), b.begin(),
			[](unsigned char c) {
				return std::tolower(c);
			});

		for (int i = numberBase; i < 36; i++) {
			if (a.find(alpha[i]) != std::string::npos || b.find(alpha[i]) != std::string::npos)
				return false;
		}
		return true;
	}
};