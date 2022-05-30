#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**
 * @brief Transform 4x4 matrix to 3x3, by deleting 1 row and 1 col.
 *
 * @param arr, int, int, int
 * @return  int
 */
int get_minors_det(int initial_matrix[], int str_to_del, int col_to_del, int initial_length);

/**
 * @brief Find determinant 4x4 matrix.
 *
 * @param arr, int
 * @return  int
 */
int get_det(int matrix[], int length);