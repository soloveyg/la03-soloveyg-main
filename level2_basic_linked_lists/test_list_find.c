#include "unity.h"
#include "list.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Search a list of length 0
 */
void test_zero_find(void) {
    struct ll_node* node = ll_find(NULL, 10);
    TEST_ASSERT_NULL(node);
}

/**
 * Search a list of length 1 and succeed
 */
void test_one_find_ok(void) {
    // Set up linked list with only 10
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node node = { .data = 10, NULL };
    struct ll_node* n = ll_find(&node, 10);

    TEST_ASSERT_NOT_NULL(n);
    TEST_ASSERT_EQUAL(10, n->data);
}

/**
 * Search a list of length 1 and fail
 */
void test_one_find_fail(void) {
    // Set up linked list with only 10
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node node = { .data = 10, NULL };
    struct ll_node* n = ll_find(&node, 90);

    TEST_ASSERT_NULL(n);
}

/**
 * Search a list of length 2 and succeed at the head
 */
void test_two_find_ok0(void) {
    // Set up linked list with 10 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[1]) },
            { .data = 11, .next = NULL }
    };
    struct ll_node* n = ll_find(nodes, 10);

    TEST_ASSERT_NOT_NULL(n);
    TEST_ASSERT_EQUAL(10, n->data);
}

/**
 * Search a list of length 2 and succeed at the tail
 */
void test_two_find_ok1(void) {
    // Set up linked list with 10 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[1]) },
            { .data = 11, .next = NULL }
    };
    struct ll_node* n = ll_find(nodes, 11);

    TEST_ASSERT_NOT_NULL(n);
    TEST_ASSERT_EQUAL(11, n->data);
}

/**
 * Search a list of length 2 and fail
 */
void test_two_find_fail(void) {
    // Set up linked list with 10 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[1]) },
            { .data = 11, .next = NULL }
    };
    struct ll_node* n = ll_find(nodes, 90);

    TEST_ASSERT_NULL(n);
}

/**
 * Search a of list of length 4 and find at head
 */
void test_four_find_ok0(void) {
    // Set up linked list with 10 | 12 | 13 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[2]) },
            { .data = 11, .next = NULL },
            { .data = 12, .next = &(nodes[3]) },
            { .data = 13, .next = &(nodes[1]) },
    };

    struct ll_node* n = ll_find(nodes, 10);

    TEST_ASSERT_NOT_NULL(n);
    TEST_ASSERT_EQUAL(10, n->data);
}

/**
 * Search a of list of length 4 and find at next
 */
void test_four_find_ok1(void) {
    // Set up linked list with 10 | 12 | 13 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[2]) },
            { .data = 11, .next = NULL },
            { .data = 12, .next = &(nodes[3]) },
            { .data = 13, .next = &(nodes[1]) },
    };

    struct ll_node* n = ll_find(nodes, 12);

    TEST_ASSERT_NOT_NULL(n);
    TEST_ASSERT_EQUAL(12, n->data);
}

/**
 * Search a of list of length 4 and find at tail
 */
void test_four_find_ok2(void) {
    // Set up linked list with 10 | 12 | 13 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[2]) },
            { .data = 11, .next = NULL },
            { .data = 12, .next = &(nodes[3]) },
            { .data = 13, .next = &(nodes[1]) },
    };

    struct ll_node* n = ll_find(nodes, 11);

    TEST_ASSERT_NOT_NULL(n);
    TEST_ASSERT_EQUAL(11, n->data);
}

/**
 * Search a of list of length 4 and fail to find it
 */
void test_four_find_fail(void) {
    // Set up linked list with 10 | 12 | 13 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[2]) },
            { .data = 11, .next = NULL },
            { .data = 12, .next = &(nodes[3]) },
            { .data = 13, .next = &(nodes[1]) },
    };

    struct ll_node* n = ll_find(nodes, 90);

    TEST_ASSERT_NULL(n);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_zero_find);
    RUN_TEST(test_one_find_ok);
    RUN_TEST(test_one_find_fail);

    RUN_TEST(test_two_find_ok0);
    RUN_TEST(test_two_find_ok1);
    RUN_TEST(test_two_find_fail);

    RUN_TEST(test_four_find_ok0);
    RUN_TEST(test_four_find_ok1);
    RUN_TEST(test_four_find_ok2);
    RUN_TEST(test_four_find_fail);

    return UNITY_END();
}
