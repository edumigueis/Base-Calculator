#include <iostream>
#include<string>
#include <stdlib.h>
#include "Adder.cpp"
#include "Subtractor.cpp"
#include "Multiplier.cpp"

using std::string;

class Operator {
private:
	string memberA, memberB;
	int base;

public:
	Operator(string a, string b, int numberBase) {
		memberA = a;
		memberB = b;
		base = numberBase;
	}

	string add() {
		if (memberA.find('-') != std::string::npos && memberB.find('-') != std::string::npos) {
			memberA = NumberFormatter::removeMinusSign(memberA);
			memberB = NumberFormatter::removeMinusSign(memberB);
			string res = NumberFormatter::addMinusSign(Adder::add(this->memberA, this->memberB, base));
			return res;
		}
		else
			if (memberA.find('-') == std::string::npos && memberB.find('-') != std::string::npos) {
				memberB = NumberFormatter::removeMinusSign(memberB);
				return Subtractor::subtract(this->memberA, this->memberB, base);
			} // both will be added as positive
			else
				if (memberA.find('-') != std::string::npos && memberB.find('-') == std::string::npos) {
					memberA = NumberFormatter::removeMinusSign(memberA);
					return Subtractor::subtract(this->memberB, this->memberA, base); //still have to remove minus sign
				}
				else {
					return Adder::add(this->memberA, this->memberB, base);
				}
	}

	string subtract() {
		if (memberA.find('-') != std::string::npos && memberB.find('-') == std::string::npos) {
			memberA = NumberFormatter::removeMinusSign(memberA);
			string res = NumberFormatter::addMinusSign(Adder::add(this->memberA, this->memberB, base));
			return res;
		}
		else
			if (memberA.find('-') == std::string::npos && memberB.find('-') != std::string::npos) {
				memberB = NumberFormatter::removeMinusSign(memberB);
				return Adder::add(this->memberA, this->memberB, base);
			} // both will be added as positive
			else
				if (memberA.find('-') != std::string::npos && memberB.find('-') != std::string::npos) {
					memberB = NumberFormatter::removeMinusSign(memberB);
					memberA = NumberFormatter::removeMinusSign(memberA);
					return Subtractor::subtract(this->memberB, this->memberA, base); //still have to remove minus sign
				}
				else {
					return Subtractor::subtract(this->memberA, this->memberB, base); //both numbers are positive and minus operation will be performed
				}
	}

	string multiply() {
		if (memberA.find('-') != std::string::npos && memberB.find('-') != std::string::npos) {
			return Multiplier::multiply(this->memberA, this->memberB, base);
		}
		else {
			if (memberA.find('-') != std::string::npos && memberB.find('-') || memberB.find('-') != std::string::npos) {
				memberB = NumberFormatter::removeMinusSign(memberB);
				memberA = NumberFormatter::removeMinusSign(memberA);
				return NumberFormatter::addMinusSign(Multiplier::multiply(this->memberA, this->memberB, base));
			}
			else {
				return Multiplier::multiply(this->memberA, this->memberB, base);
			}
		}
	}

	string divide() {
		if (memberA.find('-') != std::string::npos && memberB.find('-') != std::string::npos) {
			//return Divider::divide(this->memberA, this->memberB, base);
		}
		else {
			if (memberA.find('-') != std::string::npos && memberB.find('-') || memberB.find('-') != std::string::npos) {
				memberB = NumberFormatter::removeMinusSign(memberB);
				memberA = NumberFormatter::removeMinusSign(memberA);
				//return Divider::divide(this->memberA, this->memberB, base);
			}
			else {
				//return Divider::divide(this->memberA, this->memberB, base);
			}
		}
		return "3";
	}
};
