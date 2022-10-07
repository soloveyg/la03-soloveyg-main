#include "unity.h"
#include <locale.h>
#include <string.h>
#include <stdlib.h> // For NULL
#include "pointers.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Test range of 0
 */
void test_range_zero(void) {
    int *result = range(0);

    TEST_ASSERT_NULL(result);
}

/**
 * Test range of 1
 */
void test_range_one(void) {
    int expected[] = {1};
    int *result = range(1);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, result, 1);
    free(result);
    result = NULL;
}

/**
 * Test range of 4
 */
void test_range_four(void) {
    int expected[] = {1, 2, 3, 4};
    int *result = range(4);

    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, result, 4);
    free(result);
    result = NULL;
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_range_zero);
    RUN_TEST(test_range_one);
    RUN_TEST(test_range_four);

    return UNITY_END();
}
