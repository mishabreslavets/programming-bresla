#include "lib.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version latest
 */
int main() {
    char str[80];
    char s[100];
    FILE* ff=fopen("../assets/input.txt","r");
    if(ff!=NULL)
    {
        while(!feof(ff))
        {
            fscanf(ff,"%s ",s);
            printf("%s ",s);

        }
        printf("\n");
        fclose(ff);
    }else{
        printf("error");
    }
    printf("Insert string you want numbers to extract from: \n");
    fgets(str, 100, stdin);
    find_digits(str);
    return 0;
}