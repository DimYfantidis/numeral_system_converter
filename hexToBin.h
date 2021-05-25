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
#endif //MORE_MEMORY

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

#ifndef READ_HEX
#define READ_HEX
char *readHex() {
    auto *read = new char[1000];
    fgets(read,1000,stdin);
    read[strcspn(read,"\n")] = '\0';

    size_t len = strlen(read);
    auto *result = new char[len + 1];
    memcpy(result, read, (len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        if ((result[i] < '0' || result[i] > '9') && (result[i] < 'A' || result[i] > 'F'))
            terminate(2);
    }

    delete[] read;
    return result;
}
#endif //READ_HEX

char *hexToBinary(const char *N_0x) {
    size_t hexLength = strlen(N_0x);
    size_t size = (4 * hexLength) + 1;
    auto *N_0b = new char[size + 1];

    strcpy(N_0b, binaryQuantityHexRange[val(N_0x[0])]);
    for (int i = 1; i < hexLength; i++) {
        strcat(N_0b, binaryQuantityHexRange[val(N_0x[i])]);
    }
    memmove(N_0b, N_0b + strcspn(N_0b,"1"), (strlen(N_0b) - strcspn(N_0b,"1") + 1) * sizeof(char));

    return N_0b;
}


#endif //HEX_TO_BIN_H
