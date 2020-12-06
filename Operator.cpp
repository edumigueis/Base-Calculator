#include <iostream>
#include<string>
#include <stdlib.h>

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
        //return Somador.somar(numeroUm, numeroDois, base);
        return "0";
    }

    string subtract() {
        //return Subtrador.subtrair(numeroUm, numeroDois, base);
        return "0";
    }

    string multiply() {
        //return Multiplicador.multiplicar(numeroUm, numeroDois, base);
        return "0";
    }

    string divide() {
        //return Divisora.dividir(numeroUm, numeroDois, base);
        return "0";
    }

};
