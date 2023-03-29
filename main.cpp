#include <iostream>
#include "RationalNumber.h"

using namespace std;

RationalNumber rnAsk () {
    int numerator;
    int denominator;
    string rnInput;
    bool rnInputValid = false;

    //Regex filters
    regex rnInputRegexInt1("^-?[0-9]+$");
    regex rnInputRegexInt2("^-?[0-9]+,-?[0-9]+$");
    regex rnInputRegexFraction("^-?[0-9]+\\/-?[0-9]+$");

    //Assess Input and re-ask for input until format is valid
    while (rnInputValid == false) {
        cout << "Please enter a rational number. The following formats are acceptable:"
             << "\n\t- Nothing (will be interpreted as 0"
             << "\n\t- A single integer"
             << "\n\t- 2 integers separated by a comma (\",\")"
             << "\n\t- A fraction (x/y)"
             << "\n\tNOTE: the system will reject decimals and non-numeric entries" << endl;
        getline(cin, rnInput);

        /*
            Null string
            Validation: check for decimals and non-numeric entries
            Integer: should not contain , or /
                //https://stackoverflow.com/questions/43629363/how-to-check-if-a-string-contains-a-char
            2 Integers: contains ,
            String (fraction): contains /
        */

        if (rnInput.empty() == true) {
            numerator = 0;
            rnInputValid = true;
            return RationalNumber();
        } else if (regex_match(rnInput, rnInputRegexInt1) == true) {
            //Take entry as numerator
            rnInputValid = true;
            //cout << numerator << endl;
            return RationalNumber(stoi(rnInput));
        } else if (regex_match(rnInput, rnInputRegexInt2) == true) {
            //Split entry by comma
            //First part is numerator; second part is denominator
            size_t rnInputIndex;
            rnInputIndex = rnInput.find(',');
            numerator = stoi(rnInput.substr(0, rnInputIndex));
            denominator = stoi(rnInput.substr(rnInputIndex + 1));
            rnInputValid = true;
            return RationalNumber(numerator, denominator);
        } else if (regex_match(rnInput, rnInputRegexFraction) == true) {
            size_t rnInputIndex;
            rnInputIndex = rnInput.find('/');
            denominator = stoi(rnInput.substr(rnInputIndex + 1));

            if (denominator == 0) {
                cout << "ERROR: denominator cannot be 0!" << endl;
            } else {
                rnInputValid = true;
                return RationalNumber(rnInput);
            }
        } else {
            cout << "ERROR: invalid format for rational number!" << endl;
        }
    }
}

void comparisonGreaterGet(bool comparisonGreater, RationalNumber rn1Input, RationalNumber rn2Input) {
    string comparisonGreaterString;

    if (comparisonGreater == 0) {
        comparisonGreaterString = "NOT ";
    } else {
        comparisonGreaterString = "";
    }

    cout << rn1Input << " is " <<  comparisonGreaterString << "greater than " << rn2Input << endl;
}

void comparisonLessGet(bool comparisonLess, RationalNumber rn1Input, RationalNumber rn2Input) {
    string comparisonLessString;

    if (comparisonLess == 0) {
        comparisonLessString = "NOT ";
    } else {
        comparisonLessString = "";
    }

    cout << rn1Input << " is " <<  comparisonLessString << "less than " << rn2Input << endl;
}

void comparisonEqualGet(bool comparisonEqual, RationalNumber rn1Input, RationalNumber rn2Input) {
    string comparisonEqualString;

    if (comparisonEqual == 0) {
        comparisonEqualString = "NOT ";
    } else {
        comparisonEqualString = "";
    }

    cout << rn1Input << " is " <<  comparisonEqualString << "equal to " << rn2Input << endl;
}

int main() {
    cout << "Rational Number Calculator" << endl;
    RationalNumber rn1;
    RationalNumber rn2;

    //Ask for numbers from user
    rn1 = rnAsk();
    rn2 = rnAsk();

    cout << "" << endl;

    cout << "\n<< OVERLOADING AND FRACTION NORMALIZATION\n" << endl;

    //Overload << test
    cout << rn1 << endl;
    cout << "Normalizing..." << endl;
    rn1.normalizer();
    cout << "Normalized Rational Number: " << rn1 << endl;

    cout << rn2 << endl;
    cout << "Normalizing..." << endl;
    rn2.normalizer();
    cout << "Normalized Rational Number: " << rn2 << endl;

    cout << "\nMATHEMATICAL OPERATIONS\n" << endl;

    //Mathematical Operations
    RationalNumber rnFinal;

    rnFinal = rn1 + rn2;
    cout << rn1 << " + " << rn2 << " = " << rnFinal << endl;
    rnFinal.normalizer();
    cout << "Normalized result: " << rnFinal << "\n" << endl;

    rnFinal = rn1 - rn2;
    cout << rn1 << " - " << rn2 << " = " << rnFinal << endl;
    rnFinal.normalizer();
    cout << "Normalized result: " << rnFinal << "\n" << endl;

    rnFinal = rn1 * rn2;
    cout << rn1 << " * " << rn2 << " = " << rnFinal << endl;
    rnFinal.normalizer();
    cout << "Normalized result: " << rnFinal << "\n" << endl;

    rnFinal = rn1 / rn2;
    cout << rn1 << " / " << rn2 << " = " << rnFinal << endl;
    rnFinal.normalizer();
    cout << "Normalized result: " << rnFinal << "\n" << endl;

    cout << "COMPARISONS\n" << endl;

    comparisonGreaterGet(rn1 > rn2, rn1, rn2);
    comparisonLessGet(rn1 < rn2, rn1, rn2);
    comparisonEqualGet(rn1 == rn2, rn1, rn2);

    return 0;
}