#include "unity.h"
#include <locale.h>
#include <string.h>
#include <stdlib.h> // For NULL
#include "pointers.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Test invalid string
 */
void test_null(void) {
    char *result = capitalize(NULL, 0);

    TEST_ASSERT_NULL(result);
}

/**
 * Test empty string
 */
void test_empty(void) {
    char *result = capitalize("", 0);

    TEST_ASSERT_NULL(result);
}

/**
 * Test abc
 */
void test_abc(void) {
    char *result = capitalize("abc", 3);

    TEST_ASSERT_NOT_NULL(result);
    int len = strlen(result);
    TEST_ASSERT_EQUAL(3, len);
    TEST_ASSERT_EQUAL_STRING("ABC", result);
    free(result);
    result = NULL;
}

/**
 * Test abc_DEF
 */
void test_abc_DEF(void) {
    char *result = capitalize("abc_DEF", 7);

    TEST_ASSERT_NOT_NULL(result);
    int len = strlen(result);
    TEST_ASSERT_EQUAL(7, len);
    TEST_ASSERT_EQUAL_STRING("ABC_DEF", result);
    free(result);
    result = NULL;
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();

    setlocale(LC_ALL, "C");

    RUN_TEST(test_null);
    RUN_TEST(test_empty);
    RUN_TEST(test_abc);
    RUN_TEST(test_abc_DEF);

    return UNITY_END();
}
