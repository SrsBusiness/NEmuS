#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include "test_example.h"
#include "test_ops.h"

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_example),
        cmocka_unit_test(test_exec_adc_imm),
        cmocka_unit_test(test_exec_adc_imm_carry),
        cmocka_unit_test(test_exec_adc_imm_overflow_negative),
        cmocka_unit_test(test_exec_adc_imm_zero),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
