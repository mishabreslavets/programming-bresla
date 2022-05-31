//#pragma once
#include "lib.h"
int main()
{
    FILE* finput = fopen("../assets/input.txt","r");
    if (finput == NULL) {
        printf("no such file. \n");
    }
    char symbol;
    int height;
    int width;
    fscanf(finput, "%d %d %c", &height, &width, &symbol);
    int sqr = build_triangle(symbol, height, width);
    fclose(finput);
}