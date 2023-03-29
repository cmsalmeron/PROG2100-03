//
// Created by w0438057 on 2023-03-22.
//

#ifndef INC_03_RATIONALNUMBER_H
#define INC_03_RATIONALNUMBER_H

#include <iostream>
#include <string>
#include <regex>
#include <cmath>

const int STRINGLENGTH = 256;
using namespace std;

class RationalNumber {

public:
    int numerator;
    int denominator;
    double value;

    //Default Constructor
    RationalNumber ();

    //1-Argument Constructor
    RationalNumber (int);

    //2-Argument Constructor
    RationalNumber (int, int);

    //String-Argument Constructor
    RationalNumber (string);

    //Overload +
    RationalNumber operator+(RationalNumber RationalNumberInput);

    //Overload -
    RationalNumber operator-(RationalNumber RationalNumberInput);

    //Overload *
    RationalNumber operator*(RationalNumber RationalNumberInput);

    //Overload /
    RationalNumber operator/(RationalNumber RationalNumberInput);

    //Overload =
    //RationalNumber operator=(RationalNumber RationalNumberInput);

    //Overload >
    bool operator>(RationalNumber RationalNumberInput);

    //Overload <
    bool operator<(RationalNumber RationalNumberInput);

    //Overload ==
    bool operator==(RationalNumber RationalNumberInput);

    //Overload <<
    friend ostream &operator<<(ostream& output, const RationalNumber &rationalNumberInput);

    //Get functions
    int numeratorGet();
    int denominatorGet();

    //Set functions
    void numeratorSet();
    void denominatorSet();

    void normalizer();

    void printTemp();
};

#endif //INC_03_RATIONALNUMBER_H