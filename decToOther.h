#ifndef DEC_TO_OTHER_H
#define DEC_TO_OTHER_H

#include <cstring>

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

char *decToOther(unsigned long long N, short int base) {
    unsigned long size = 2;
    auto *result = new char[size];
    int i = 0;
    while (N > base - 1) {
        if (i == size - 2)
            result = moreMemory(result, size, 2);
        result[i++] = digit[N % base];
        N /= base;
    }
    result[i++] = digit[N % base];
    result[i] = '\0';

    reverseString(result);

    return result;
}

#endif //DEC_TO_OTHER_H