/*
Authors: Eduardo Migueis and Rodrigo Smith.
Repository: https://github.com/edumigueis/Base-Calculator
License: MIT License.
*/
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
			Adder adder(memberA, memberB, base);
			string res = NumberFormatter::addMinusSign(adder.add());
			return res;
		}
		else
			if (memberA.find('-') == std::string::npos && memberB.find('-') != std::string::npos) {
				memberB = NumberFormatter::removeMinusSign(memberB);
				Subtractor sub(this->memberA, this->memberB, base);
				return sub.subtract();
			} // both will be added as positive
			else
				if (memberA.find('-') != std::string::npos && memberB.find('-') == std::string::npos) {
					memberA = NumberFormatter::removeMinusSign(memberA);
					Subtractor sub(this->memberB, this->memberA, base);
					return sub.subtract(); //still have to remove minus sign
				}
				else {
					Adder adder(memberA, memberB, base);
					return adder.add();
				}
	}

	string subtract() {
		if (memberA.find('-') != std::string::npos && memberB.find('-') == std::string::npos) {
			memberA = NumberFormatter::removeMinusSign(memberA);
			Adder adder(memberA, memberB, base);
			string res = NumberFormatter::addMinusSign(adder.add());
			return res;
		}
		else
			if (memberA.find('-') == std::string::npos && memberB.find('-') != std::string::npos) {
				memberB = NumberFormatter::removeMinusSign(memberB);
				Adder adder(memberA, memberB, base);
				return adder.add();
			} // both will be added as positive
			else
				if (memberA.find('-') != std::string::npos && memberB.find('-') != std::string::npos) {
					memberB = NumberFormatter::removeMinusSign(memberB);
					memberA = NumberFormatter::removeMinusSign(memberA);
					Subtractor sub(this->memberB, this->memberA, base);
					return sub.subtract(); //still have to remove minus sign
				}
				else {
					Subtractor sub(this->memberA, this->memberB, base);
					return sub.subtract(); //both numbers are positive and minus operation will be performed
				}
	}

	string multiply() {
		if (memberA.find('-') != std::string::npos && memberB.find('-') != std::string::npos) {
			Multiplier mult(this->memberA, this->memberB, base);
			return mult.multiply();
		}
		else {
			if (memberA.find('-') != std::string::npos && memberB.find('-') || memberB.find('-') != std::string::npos) {
				memberB = NumberFormatter::removeMinusSign(memberB);
				memberA = NumberFormatter::removeMinusSign(memberA);
				Multiplier mult(this->memberA, this->memberB, base);
				return NumberFormatter::addMinusSign(mult.multiply());
			}
			else {
				Multiplier mult(this->memberA, this->memberB, base);
				return mult.multiply();
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
		return "";
	}
};
