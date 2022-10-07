#include "unity.h"
#include <locale.h>
#include <string.h>
#include <stdlib.h> // For NULL
#include "pointers.h"

void setUp (void) {}
void tearDown (void) {}

void test_set_max1(void) {
    int result = 0;
    set_max(1, 2, &result);

    TEST_ASSERT_EQUAL(2, result);
}

void test_set_max2(void) {
    int result = 0;
    set_max(4, 2, &result);

    TEST_ASSERT_EQUAL(4, result);
}

void test_set_max_inval(void) {
    set_max(4, 2, NULL);

    TEST_PASS();
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_set_max1);
    RUN_TEST(test_set_max2);
    RUN_TEST(test_set_max_inval);

    return UNITY_END();
}
