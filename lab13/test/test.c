#include"../src/lib.h"
#include <check.h>
#include <stdio.h>

START_TEST(test_triangle)
{
    int height = 15;
    int width = 31;
    char symbol = '$';
    int expected = 225;
    int actual = build_triangle(symbol, height, width);
    ck_assert_int_eq(expected, actual);
}END_TEST

int main(void){
    Suite *s = suite_create("Proga");
    TCase *tc_core = tcase_create("Laba13");

    tcase_add_test(tc_core, test_triangle);

    suite_add_tcase(s, tc_core);
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 1 : 0;
};