#include "lib.h"
#include "check.h"
// TODO; write test
START_TEST(test_sqr){
    int input[] = {4, 25, 1, 0};
    int expected[] = {16, 62, 1, 0};
    for(int i = 0; i < 4; i++){
        int actual = sqr(input[i]);
        ck_assert_int_eq(expected[i], actual);
    }
}END_TEST



int main(void){
    Suite *s = suite_create("Proga");
    TCase *tc_core = tcase_create("Laba9");

    tcase_add_test(tc_core, test_sqr);

    suite_add_tcase(s, tc_core);
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 1 : 0;
};