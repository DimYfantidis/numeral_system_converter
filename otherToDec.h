#ifndef OTHER_TO_DEC_H
#define OTHER_TO_DEC_H

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#ifndef ERR_TERMINATE
#define ERR_TERMINATE
const char *ERR_MESSAGE[] = {
        "ERROR: Wrong Base Input!",
        "ERROR: Wrong Digit Input!",
        "ERROR: Number's digits do not correspond to numerical base!"
};
const unsigned int SIZE_OF_ERROR_LUT = sizeof(ERR_MESSAGE) / sizeof(char *);

[[noreturn]] void terminate (unsigned short code) {
    if (code != 0 && code <= SIZE_OF_ERROR_LUT) {
        cerr << endl << ERR_MESSAGE[code - 1] << endl;
    }
    system("PAUSE");
    exit (code);
}
#endif //ERR_TERMINATE

#ifndef DIGIT_VALUE
#define DIGIT_VALUE
short int val (const char d) {
    bool A = d >= '0' && d <= '9';
    bool B = d >= 'A' && d <= 'F';

    if (!A && !B) {
        terminate(2);
    }
    return (A ? (short int)(d - 48) : (short int)(d - 55));
}
#endif //DIGIT_VALUE

unsigned long long numToDecimal (const char *N, short int base) {
    unsigned long long result = 0;
    size_t digits = strlen(N);

    for (size_t i = 0; i < digits; i++) {
        if (val(N[i]) >= base) {
            terminate(3);
        }
        result += (unsigned long long)(val(N[i]) * pow(base, digits - i - 1));
    }
    return result;
}

#ifndef READ_STRING
#define READ_STRING
char *readFromKeyboard() {
    auto *read = new char[65];
    fgets(read,65,stdin);
    read[strcspn(read,"\n")] = '\0';

    auto *result = new char[strlen(read) + 1];
    strcpy(result,read);

    delete[] read;
    return result;
}
#endif //READ_STRING

#endif //OTHER_TO_DEC_H