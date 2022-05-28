#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#define N 5
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version latest
 */
int main() {

    int input[N][N] = {
            {7222,     8,     9,     14,    15    },
            {11,    22,    33,    44,    55   },
            {111,   222,   33,   444,   555  },
            {1111,  2222,  3333,  4444,  5555 },
            {11111, 22222, 33333, 44444, 55}};
    int* answer = extract_diog_and_sortit(*input, N);
    if(answer==NULL){
        printf("no memory enough\n");
        return 1;
    }
    free(answer);
    return 0;

}