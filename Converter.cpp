#include <iostream>
#include<string>
#include <stdlib.h>

using std::string;

class Converter {

public:
	static char* stringToCharArray(string toConvert) {
		char res[1024];
		strncpy(res, toConvert.c_str(), sizeof(toConvert));
		res[sizeof(res) - 1] = '\0';
		return res;
	}
};