#include "../src/lib.h"
#include <check.h>
#include<stdio.h>
/**
 * @file main.c
 * @brief Файл
 *
 * @author Bresla
 * @version latest
 */
START_TEST(test_result)
{
    int input[5][5] = {
            {3,  2,  1, 5, 8},
            {9,  4,  71, 12, 65},
            {851, 16, 14, 16, 45},
            {91,  4,  12, 45, 65},
            {831, 16, 16, 56, 32}
    };
    int N = 5;
    int* actual = extract_diog_and_sortit(*input, N);
    int expected[] = {3, 4, 14, 32, 45};
    for(int i = 0; i < N; i++) {
        ck_assert_int_eq(expected[i], actual[i]);
    }
}END_TEST
int main(void){
    Suite *s = suite_create("Proga");
    TCase *tc_core = tcase_create("Laba10");

    tcase_add_test(tc_core, test_result);

    suite_add_tcase(s, tc_core);
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 1 : 0;
};