#include <iostream>
#include<string>
#include <stdlib.h>
#include "Adder.cpp"

using std::string;

class Operator {

	string memberA, memberB;
	int base;

public:
	Operator(string a, string b, int numberBase) {
		memberA = a;
		memberB = b;
		base = numberBase;
	}

	string add() {
		return Adder::add(this->memberA, this->memberB, base);
	}

	string subtract() {
		//return Subtractor::subtract(this->memberA, this->memberB, base);
		return "1";
	}

	string multiply() {
		//return Multiplier::multiply(this->memberA, this->memberB, base);
		return "2";
	}

	string divide() {
		//return Divider::divide(this->memberA, this->memberB, base);
		return "3";
	}
};
