//
// Created by w0438057 on 2023-03-22.
//

#include "RationalNumber.h"
#include <cstdlib>

int RationalNumber::numeratorGet() {
    return this->numerator;
}

int RationalNumber::denominatorGet() {
    return this->denominator;
}

//Default Constructor
RationalNumber::RationalNumber() {
    cout << "(PROCESS: Default Constructor)" << endl;
    numerator = 0;
    denominator = 1;
}

//1-Argument Constructor
RationalNumber::RationalNumber(int numeratorInput) {
    cout << "(PROCESS: 1-Argument Constructor)";
    numerator = numeratorInput;
    denominator = 1;
}

//2-Argument Constructor
RationalNumber::RationalNumber(int numeratorInput, int denominatorInput) {
    cout << "(PROCESS: 2-Argument Constructor)";
    numerator = numeratorInput;
    denominator = denominatorInput;

    if (denominator == 0) {
        cout << "ERROR: denominator cannot be 0." << endl;
    }
}

//String-Argument Constructor
RationalNumber::RationalNumber(string rnString) {
    cout << "(PROCESS: String-Argument Constructor)" << endl;
    //Break down string into fraction
    size_t rnStringIndex;
    rnStringIndex = rnString.find('/');
    numerator = stoi(rnString.substr(0, rnStringIndex));
    denominator = stoi(rnString.substr(rnStringIndex + 1));

    if (denominator == 0) {
        cout << "ERROR: denominator cannot be 0." << endl;
    }
}

//Overload +
//Source: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
RationalNumber RationalNumber::operator+(RationalNumber RationalNumberInput) {
    cout << "(PROCESS: Overloading +)";
    RationalNumber RationalNumberInitial;

    // a/b + c/d = ad/bd + cb/bd
    //Common denominator
    RationalNumberInitial.denominator = this->denominator * RationalNumberInput.denominator;
    //Resulting numerators
    int numerator0 = this->numerator *  RationalNumberInput.denominator;
    int numerator1 = RationalNumberInput.numerator * this->denominator;
    RationalNumberInitial.numerator = numerator0 + numerator1;

    return RationalNumberInitial;
}

//Overload -
RationalNumber RationalNumber::operator-(RationalNumber RationalNumberInput) {
    cout << "(PROCESS: Overloading -)";
    RationalNumber RationalNumberInitial;

    // a/b - c/d = ad/bd - cb/bd
    //Common denominator
    RationalNumberInitial.denominator = this->denominator * RationalNumberInput.denominator;
    //Resulting numerators
    int numerator0 = this->numerator *  RationalNumberInput.denominator;
    int numerator1 = RationalNumberInput.numerator * this->denominator;
    RationalNumberInitial.numerator = numerator0 - numerator1;

    return RationalNumberInitial;
}

//Overload *
RationalNumber RationalNumber::operator*(RationalNumber RationalNumberInput) {
    cout << "(PROCESS: Overloading *)";
    RationalNumber RationalNumberInitial;

    // a/b * c/d = ac/bd
    RationalNumberInitial.numerator = this->numerator * RationalNumberInput.numerator;
    RationalNumberInitial.denominator = this->denominator * RationalNumberInput.denominator;

    return RationalNumberInitial;
}

//Overload /
RationalNumber RationalNumber::operator/(RationalNumber RationalNumberInput) {
    cout << "(PROCESS: Overloading /)";
    RationalNumber RationalNumberInitial;

    // a/b / c/d = a/b * d/c
    RationalNumberInitial.numerator = this->numerator * RationalNumberInput.denominator;
    RationalNumberInitial.denominator = this->denominator * RationalNumberInput.numerator;

    return RationalNumberInitial;
}

//Overload >
//Compare values
bool RationalNumber::operator>(RationalNumber RationalNumberInput) {
    cout << "(PROCESS: Overloading Compare >)";
    bool compareGreater = false;
    double RationalNumberInputValue;
    this->value = (double)this->numerator / (double)this->denominator;
    RationalNumberInputValue = (double)RationalNumberInput.numerator / (double)RationalNumberInput.denominator;

    if (this->value > RationalNumberInputValue) {
        compareGreater = true;
    }

    return compareGreater;
}

//Compare values
bool RationalNumber::operator<(RationalNumber RationalNumberInput) {
    cout << "(PROCESS: Overloading Compare <)";
    bool compareLess = false;
    double RationalNumberInputValue;
    this->value = (double)this->numerator / (double)this->denominator;
    RationalNumberInputValue = (double)RationalNumberInput.numerator / (double)RationalNumberInput.denominator;

    if (this->value < RationalNumberInputValue) {
        compareLess = true;
    }

    return compareLess;
}

//Compare values
bool RationalNumber::operator==(RationalNumber RationalNumberInput) {
    cout << "(PROCESS: Overloading Compare ==)";
    bool compareEqual = false;
    double RationalNumberInputValue;
    this->value = (double)this->numerator / (double)this->denominator;
    RationalNumberInputValue = (double)RationalNumberInput.numerator / (double)RationalNumberInput.denominator;

    if (this->value == RationalNumberInputValue) {
        compareEqual = true;
    }

    return compareEqual;
}

//Overload <<
ostream &operator<<(ostream &output, const RationalNumber &rationalNumberInput) {
    cout << "(PROCESS: Overloading <<) ";
    output << rationalNumberInput.numerator << "/" << rationalNumberInput.denominator;
    return output;
}

//Normalizer (GCF Finder and Fraction Reducer)
void RationalNumber::normalizer() {
    cout << "(PROCESS: Normalizer)" << endl;
    int gcf;
    int limit;

    if (this->denominator < 0) {
        this->denominator = this->denominator * -1;
        this->numerator = this->numerator * -1;
    }

    if (abs(this->numerator) <= abs(this->denominator)) {
        limit = abs(this->numerator);
    } else {
        limit = abs(this->denominator);
    }

    //cout << limit << endl;

    for (int i = 1; i < (limit + 1); i++) {
        double gcfTestNumerator = (double)this->numerator / i;
        double gcfTestDenonimator = (double)this->denominator / i;

        //cout << i << ":" << gcfTestNumerator << "|" << gcfTestDenonimator << endl;

        if (((gcfTestNumerator - trunc(gcfTestNumerator)) == 0)  && ((gcfTestDenonimator - trunc(gcfTestDenonimator)) == 0)) {
            gcf = i;
        }
    }

    if (gcf > 1) {
        this->numerator = this->numerator / gcf;
        this->denominator = this->denominator / gcf;
    }
}

void RationalNumber::printTemp() {
    cout << numerator << "/" << denominator << endl;
}