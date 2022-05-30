#include"../src/lib.h"
#include <check.h>
#include<stdio.h>
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version latest
 */
START_TEST(test_det)
{
    int length = 4;
    int initial_matrix[4][4] = {
            { 4, 6, 5, 3},
            {85, 4, 3, 1},
            { 3, 5, 4, 1},
            { 6, 4, 2, 9}};
    double expected[4][4]={
            {  0.004473,  0.012141, -0.014058, -0.001278},
            { -1.794888, -0.014696,  2.069649,  0.369968},
            {  2.161661,  0.010224, -2.222364, -0.474760},
            {  0.314377, -0.003834, -0.416613,  0.053035}};
    int determinant = get_det((int*)initial_matrix, length);
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
    int matches = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if(rev_matrix[i][j] - expected[i][j]< 0.0001){
                matches++;
            }
        }
    }
        ck_assert_int_eq(matches, 16);
}END_TEST

int main(void){
    Suite *s = suite_create("Proga");
    TCase *tc_core = tcase_create("Laba11");

    tcase_add_test(tc_core, test_det);

    suite_add_tcase(s, tc_core);
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 1 : 0;
};