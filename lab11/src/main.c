#include "lib.h"


/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version latest
 */

int main() {
//    long ltime = time (NULL);
//    int stime = (unsigned int) ltime/2;
//    srand(stime);

    char s[100];
    FILE* ff=fopen("../assets/input.txt","r");
    if(ff!=NULL)
    {
        while(!feof(ff))
        {
            fscanf(ff,"%s",s);
//            if(s[0]=='a' || s[0]=='o' || s[0]=='u' || s[0]=='i'||  s[0]=='y' )
//                s[0]-='a'-'A';
            printf("%s",s);

        }
        printf("\n");
        fclose(ff);
    }else{
        printf("error");
    }

    int length = 4;
    int initial_matrix[4][4];
    printf("Algorithm works properly only with 4x4 matrix. Input initial_matrix you want to reverse: \n");
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
//            *(*(initial_matrix + i) + j) = rand()%10+1;
            scanf("%d", *(initial_matrix + i) + j);
        }
    }
    int determinant = get_det((int*) initial_matrix, length);
    int trans_alg_add[4][4];
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if((i+j)%2 == 0) {
                trans_alg_add[j][i] = get_minors_det((int*)initial_matrix, i, j, length);
            }else{
                trans_alg_add[j][i] = get_minors_det((int*)initial_matrix, i, j, length) * -1;
            }
        }
    }

//    printf("Deter %d \n", determinant);
    double rev_matrix[4][4];
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            rev_matrix[i][j] = ((double ) trans_alg_add[i][j]/determinant);
        }
    }
    for (int i = 0; i < length; ++i) {
        printf("[ ");
        for (int j = 0; j < length; ++j) {
            if(rev_matrix[i][j] > 0) {
                printf(" %f ", rev_matrix[i][j]);
            }else{
                printf("%f ", rev_matrix[i][j]);
            }
        }
        printf("]\n");
    }
//    free(determinant);
    return 0;
}