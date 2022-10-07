#include "unity.h"
#include "list.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Get head of list of length 0
 */
void test_zero_head(void) {
    struct ll_node* head = ll_head(NULL);
    TEST_ASSERT_NULL(head);
}

/**
 * Get head of list of length 1
 */
void test_one_head(void) {
    // Set up linked list with only 10
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node node = { .data = 10, NULL };
    struct ll_node* head = ll_head(&node);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL(10, head->data);
}

/**
 * Get head of list of length 2
 */
void test_two_head(void) {
    // Set up linked list with 10 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[1]) },
            { .data = 11, .next = NULL }
    };
    struct ll_node* head = ll_head(nodes);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL(10, head->data);
}

/**
 * Get head of list of length 4
 */
void test_four_head(void) {
    // Set up linked list with 10 | 12 | 13 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[2]) },
            { .data = 11, .next = NULL },
            { .data = 12, .next = &(nodes[3]) },
            { .data = 13, .next = &(nodes[1]) },
    };

    struct ll_node* head = ll_head(nodes);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL(10, head->data);
}

/**
 * Get tail of list of length 0
 */
void test_zero_tail(void) {
    struct ll_node* tail = ll_tail(NULL);
    TEST_ASSERT_NULL(tail);
}

/**
 * Get tail of list of length 1
 */
void test_one_tail(void) {
    // Set up linked list with only 10
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node node = { .data = 10, NULL };
    struct ll_node* tail = ll_tail(&node);

    TEST_ASSERT_NOT_NULL(tail);
    TEST_ASSERT_EQUAL(10, tail->data);
}

/**
 * Get tail of list of length 2
 */
void test_two_tail(void) {
    // Set up linked list with 10 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[1]) },
            { .data = 11, .next = NULL }
    };
    struct ll_node* tail = ll_tail(nodes);

    TEST_ASSERT_NOT_NULL(tail);
    TEST_ASSERT_EQUAL(11, tail->data);
}

/**
 * Get tail of list of length 4
 */
void test_four_tail(void) {
    // Set up linked list with 10 | 12 | 13 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[2]) },
            { .data = 11, .next = NULL },
            { .data = 12, .next = &(nodes[3]) },
            { .data = 13, .next = &(nodes[1]) },
    };

    struct ll_node* tail = ll_tail(nodes);

    TEST_ASSERT_NOT_NULL(tail);
    TEST_ASSERT_EQUAL(11, tail->data);
}

/**
 * Test list of length 0
 */
void test_zero(void) {
    int result = ll_size(NULL);
    TEST_ASSERT_EQUAL(0, result);
}

/**
 * Test list of length 1
 */
void test_one(void) {
    // Set up linked list with only 10
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node node = { .data = 10, NULL };
    int result = ll_size(&node);

    TEST_ASSERT_EQUAL(1, result);
}

/**
 * Test list of length 2
 */
void test_two(void) {
    // Set up linked list with 10 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[1]) },
            { .data = 11, .next = NULL }
    };
    int result = ll_size(nodes);
    TEST_ASSERT_EQUAL(2, result);
}

/**
 * Test list of length 4
 */
void test_four(void) {
    // Set up linked list with 10 | 12 | 13 | 11
    // NOTE: Do NOT follow this linked-list set-up! Only for testing purposes!
    struct ll_node nodes[] = {
            { .data = 10, .next = &(nodes[2]) },
            { .data = 11, .next = NULL },
            { .data = 12, .next = &(nodes[3]) },
            { .data = 13, .next = &(nodes[1]) },
    };
    int result = ll_size(nodes);
    TEST_ASSERT_EQUAL(4, result);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_zero_head);
    RUN_TEST(test_one_head);
    RUN_TEST(test_two_head);
    RUN_TEST(test_four_head);

    RUN_TEST(test_zero_tail);
    RUN_TEST(test_one_tail);
    RUN_TEST(test_two_tail);
    RUN_TEST(test_four_tail);

    RUN_TEST(test_zero);
    RUN_TEST(test_one);
    RUN_TEST(test_two);
    RUN_TEST(test_four);

    return UNITY_END();
}
