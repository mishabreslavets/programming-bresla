#include "lib.h"
int build_triangle(char symbol, int height, int width){
    FILE* foutput=fopen("output.txt","w");
    int cur_width = 1;
    int sqr = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (width - cur_width)/2; j++) {
            fprintf(foutput, " ");
            fprintf(stdout, " ");
        }
        for (int j = 0; j < cur_width; j++) {
            fprintf(foutput, "%c", symbol);
            fprintf(stdout, "%c", symbol);
            ++sqr;
        }
        cur_width += 2;
        fprintf(foutput, "\n");
        fprintf(stdout, "\n");
    }
    fclose(foutput);
    return sqr;
}