#include <iostream>
#include "otherToDec.h"
#include "decToOther.h"
#include "hexToBin.h"
#include "binToHex.h"
using namespace std;

bool inputFail(istream &input) {
    if (input.fail()) {
        input.clear();
        input.ignore(1000,'\n');
        return true;
    }
    return false;
}

void halt() {
    cout << endl;
    system("PAUSE");
    system("CLS");
}

void otherToDecimal() {
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
    halt();
}

void decimalToOther() {
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
    halt();
}

void hexToBin() {
    cin.ignore(10,'\n');

    cout << "Input hexadecimal number: ";
    auto *N = readHex();

    auto *N_base_2 = hexToBinary(N);
    cout << "Base 2 representation of 0x" << N << " is: 0b" << N_base_2 << endl;
    halt();
}

void binToHex() {
    cin.ignore(10,'\n');

    cout << "Input binary number: ";
    auto *N = readBin();

    auto *N_base_16 = binToHexadecimal(N);
    cout << "Base 16 representation of 0b" << N << " is: 0x" << N_base_16 << endl;
    halt();
}

int main() {
    unsigned short select;

    while (true) {
        do {
            cout << "MENU:\nBase b to Decimal: 1\nDecimal to base b: 2\nHexadecimal to Binary: 3\nBinary to Hexadecimal: 4\nExit: 0\n\nSELECT: ";
            cin >> select;
            system("CLS");
        } while (inputFail(cin) || select > 4);

        switch (select) {
            case 1: otherToDecimal(); break;
            case 2: decimalToOther(); break;
            case 3: hexToBin(); break;
            case 4: binToHex(); break;
            default: break;
        }
        if (select == 0)
            break;
    }

    return 0;
}
