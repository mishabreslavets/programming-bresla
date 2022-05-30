#include "lib.h"
int get_minors_det(int initial_matrix[], int str_to_del, int col_to_del, int initial_length){
    int det = 0;
    int diog = 1;
    int rev_diog = 1;
    int minor_length = initial_length - 1;
    int** matrix = malloc((unsigned )minor_length * sizeof(int*));
    for(int i = 0; i < minor_length; i++){
        *(matrix + i) = malloc(((unsigned )minor_length * sizeof(int)));
    }
    for (int curr_str = 0; curr_str < minor_length; ++curr_str) {
        if(curr_str < str_to_del) {
            for (int curr_col = 0; curr_col < minor_length; ++curr_col) {
                if (curr_col < col_to_del) {
                    matrix[curr_str][curr_col] = *(initial_matrix + (curr_str % initial_length * initial_length) + curr_col % initial_length);
                } else {
                    matrix[curr_str][curr_col] = *(initial_matrix + (curr_str % initial_length * initial_length) + (curr_col + 1) % initial_length);
                }
            }
        }else{
            for (int curr_col = 0; curr_col < minor_length; ++curr_col) {
                if (curr_col < col_to_del) {
                    matrix[curr_str][curr_col] = *(initial_matrix + ((curr_str + 1) * initial_length) + (curr_col));
                } else {
                    matrix[curr_str][curr_col] = *(initial_matrix + ((curr_str + 1) * initial_length) + (curr_col + 1));
                }
            }
        }
    }

    for(int i = 0; i < minor_length; i++) {
        for (int j = 0; j < minor_length; j++) {
            diog *= matrix[j][(j + i) % minor_length];
            rev_diog *= matrix[(minor_length - j + i) % minor_length][j % minor_length];
        }
        det += diog;
        det -= rev_diog;
        diog = 1;
        rev_diog = 1;
    }
    return det;
}

int get_det(int matrix[], int length) {
    int det = 0;
    for(int i = 0; i < length; i++) {
        if(i%2 == 0) {
            det += get_minors_det(matrix, 0, i, length) * *(matrix + i);
        }else{
            det += get_minors_det(matrix, 0, i, length) * *(matrix + i) * -1;
        }
    }
    return det;
}
