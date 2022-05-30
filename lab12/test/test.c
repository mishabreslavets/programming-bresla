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
START_TEST(test_get)
{
    int length = 4;
    char str[1000] = "Загальні втрати противника: особовий склад - 30350, гелікоптери - 174, танки - 1349, ББД - 3282, засоби ППО - 93, РСЗВ 205, автотехіка 2258, спецтехніка -48";
    int expected = 27;
    int actual = find_digits(str);
    ck_assert_int_eq(expected, actual);
}END_TEST

int main(void){
    Suite *s = suite_create("Proga");
    TCase *tc_core = tcase_create("Laba12");

    tcase_add_test(tc_core, test_get);

    suite_add_tcase(s, tc_core);
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 1 : 0;
};