#include <iostream>
#include "otherToDec.h"
#include "decToOther.h"
#include "hexToBin.h"
#include "binToHex.h"
using namespace std;

void otherToDecimal() {
    system("CLS");

    char *N;
    short int base;

    cout << "Give base of number: ";
    cin >> base;
    cout << "Give number: ";
    N = readFromKeyboard();

    cout << endl;
    if (base < 2 || base > 16) {
        terminate(1);
    }

    unsigned long long N_base_10 = numToDecimal(N,base);
    cout << endl << "Base 10 representation of (" << N << ")" << base << " is: " << N_base_10 << endl;
    system("PAUSE");
}

void decimalToOther() {
    system("CLS");

    unsigned long long N;
    short int base;
    cout << "Give number: ";
    cin >> N;
    cout << "Give numerical base:";
    cin >> base;

    cout << endl;
    if (base < 2 || base > 16) {
        terminate(1);
    }

    cout << "Base " << base << " representation of " << N << " is: " << changeBase(N,base) << endl;
    system("PAUSE");
}

void hexToBin() {
    system("CLS");
    cin.ignore(10,'\n');

    char *N;
    cout << "Input hexadecimal number: ";
    N = readFromKeyboard();

    auto *N_base_2 = hexToBinary(N);
    cout << "Base 2 representation of " << N << " is: " << N_base_2 << endl;

    system("PAUSE");
}

void binToHex() {
    system("CLS");
};

int main() {
    unsigned short select;

    cout << "MENU:\nBase b to Decimal: 1\nDecimal to base b: 2\nHexadecimal to Binary: 3\nBinary to Hexadecimal: 4\nExit: 0\n\nSELECT: ";
    cin >> select;

    switch(select) {
        case 1: otherToDecimal(); break;
        case 2: decimalToOther(); break;
        case 3: hexToBin(); break;
        case 4: binToHex(); break;
        default: break;
    }

    return 0;
}
