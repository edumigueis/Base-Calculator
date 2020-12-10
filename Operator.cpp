#include <iostream>
#include<string>
#include <stdlib.h>
#include "Adder.cpp"
#include "Subtractor.cpp"

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
		if (memberA.find('-') != std::string::npos && memberB.find('-') == std::string::npos) {
			memberA = NumberFormatter::removeMinusSign(memberA);
			Adder::add(this->memberA, this->memberB, base);
		}
		else
			if (memberA.find('-') == std::string::npos && memberB.find('-') != std::string::npos) // both will be added as positive
				Adder::add(this->memberA, this->memberB, base); //still have to remove minus sign
			else
				if (memberA.find('-') != std::string::npos && memberB.find('-') != std::string::npos) // both have minus sign
					return Subtractor::subtract(this->memberA, this->memberB, base); //still have to remove minus sign
					else {
						return Subtractor::subtract(this->memberA, this->memberB, base); //both numbers are positive and minus operation will be performed
					}

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
