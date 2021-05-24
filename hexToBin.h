#ifndef HEX_TO_BIN_H
#define HEX_TO_BIN_H

#ifndef BINARY_QUANTITY_RANGE_16
#define BINARY_QUANTITY_RANGE_16
const char *binaryQuantityHexRange[] {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
};
#endif //BINARY_QUANTITY_RANGE_16

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


#ifndef MORE_MEMORY
#define MORE_MEMORY
template <typename custom>
custom *moreMemory(custom *arr, unsigned long &size, unsigned long increment) {
    auto *temp = new custom[size];
    memcpy(temp, arr, size * sizeof(custom));
    delete[] arr;

    arr = new custom[size + increment];
    memcpy(arr, temp, size * sizeof(custom));
    delete[] temp;

    size += increment;
    return arr;
}
#endif

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
#endif

#ifndef READ_STRING
#define READ_STRING
char *readFromKeyboard() {
    auto *read = new char[65];
    fgets(read,65,stdin);
    read[strcspn(read,"\n")] = '\0';
    return read;
}
#endif //READ_STRING

char *hexToBinary(const char *N_0x) {
    size_t hexLength = strlen(N_0x);
    unsigned long size = (4 * hexLength) + 1;
    auto *N_0b = new char[size + 1];

    strcpy(N_0b, binaryQuantityHexRange[val(N_0x[0])]);
    for (int i = 1; i < hexLength; i++) {
        strcat(N_0b, binaryQuantityHexRange[val(N_0x[i])]);
    }
    memmove(N_0b, N_0b + strcspn(N_0b,"1"), (strlen(N_0b) * sizeof(char)) + 1);

    return N_0b;
}


#endif //HEX_TO_BIN_H