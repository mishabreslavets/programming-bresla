#include "lib.h"
int find_digits(char str[]){
    char* pStr = str;
    short isNumber = 0;
    int some_number = 0;
    while (*pStr) {
        if (*pStr >= '0' && *pStr <= '9') {
            isNumber = 1;
            printf("%c", *pStr);
            some_number ++;
//            printf("%d ", *pStr);
        } else {
            if (isNumber) {
                isNumber = 0;
                printf(" ");
            }
        }
        pStr++;
    }
    return some_number;
}