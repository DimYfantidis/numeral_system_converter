#ifndef BIN_TO_HEX_H
#define BIN_TO_HEX_H

#include <cstring>
#include <cmath>

#ifndef DIGITS
#define DIGITS
const char digit[] = {
        '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
};
#endif //DIGITS

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

#ifndef REVERSE_STRING
#define REVERSE_STRING
void reverseString(char *arr) {
    char temp;
    char *start = arr;
    char *end   = &arr[strcspn(arr,"\0") - 1];
    while (start < end) {
        temp = (*start);
        (*start) = (*end);
        (*end) = temp;
        start++;
        end--;
    }
}
#endif //REVERSE_STRING

char *readBin() {
    auto *read = new char[1000];
    fgets(read,1000,stdin);
    read[strcspn(read,"\n")] = '\0';

    size_t len = strlen(read);
    auto *result = new char[len + 1];
    memcpy(result, read, (len + 1) * sizeof(char));

    bool A, B;
    for (int i = 0; i < len; i++) {
        A = (result[i] < '0' || result[i] > '9') && (result[i] < 'A' || result[i] > 'F');
        B = (result[i] < '0' || result[i] > '1');
        if (B)
            terminate(A ? 2 : 3);
    }

    delete[] read;
    return result;
}

char *binToHexadecimal (char *N_0b) {
    size_t binLength = strlen(N_0b);
    size_t size = (binLength / 4) + (binLength % 4 != 0 ? 1 : 0);
    auto *N_0x = new char[size + 1];

    reverseString(N_0b);
    int i = 0;
    int j = 0;
    int hex_d = 0;
    while (N_0b[i] != '\0') {
        hex_d += (N_0b[i] - 48) * (int)pow(2, i % 4);
        i++;
        if (i % 4 == 0) {
            N_0x[j++] = digit[hex_d];
            hex_d = 0;
        }
    }
    if (i % 4 != 0) {
        N_0x[j++] = digit[hex_d];
    }
    N_0x[j] = '\0';

    reverseString(N_0b);
    reverseString(N_0x);

    return N_0x;
}

#endif //BIN_TO_HEX_H