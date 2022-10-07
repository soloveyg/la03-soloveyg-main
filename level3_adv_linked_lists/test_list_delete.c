#include "unity.h"
#include "list.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Create one item list and delete it
 */
void test_one(void) {
    struct ll_node *head = ll_create(10);
    head = ll_delete(head, 10);

    TEST_ASSERT_NULL(head);
    int result = ll_size(head);
    TEST_ASSERT_EQUAL_MESSAGE(0, result, "List length incorrect");
}

/**
 * Create two item list and delete head
 */
void test_two_head(void) {
    struct ll_node *head = ll_create(10);
    ll_append(head, 20);

    head = ll_delete(head, 10);

    TEST_ASSERT_NOT_NULL(head);
    int result = ll_size(head);
    TEST_ASSERT_EQUAL_MESSAGE(1, result, "List length incorrect");
    TEST_ASSERT_EQUAL(20, head->data);

    // Cleanup
    ll_destroy(head);
}

/**
 * Create two item list and delete tail
 */
void test_two_tail(void) {
    struct ll_node *head = ll_create(10);
    ll_append(head, 20);

    head = ll_delete(head, 20);

    TEST_ASSERT_NOT_NULL(head);
    int result = ll_size(head);
    TEST_ASSERT_EQUAL_MESSAGE(1, result, "List length incorrect");
    TEST_ASSERT_EQUAL(10, head->data);

    // Cleanup
    ll_destroy(head);
}

/**
 * Create four item list and delete head
 */
void test_four_head(void) {
    struct ll_node *head = ll_create(10);
    ll_append(head, 20);
    ll_append(head, 30);
    ll_append(head, 40);

    head = ll_delete(head, 30);

    TEST_ASSERT_NOT_NULL(head);
    int result = ll_size(head);
    TEST_ASSERT_EQUAL_MESSAGE(3, result, "List length incorrect");
    TEST_ASSERT_EQUAL(10, head->data);

    // Cleanup
    ll_destroy(head);
}


/**
 * Create four item list and delete middle
 */
void test_four_middle(void) {
    struct ll_node *head = ll_create(10);
    ll_append(head, 20);
    ll_append(head, 30);
    ll_append(head, 40);

    head = ll_delete(head, 30);

    TEST_ASSERT_NOT_NULL(head);
    int result = ll_size(head);
    TEST_ASSERT_EQUAL_MESSAGE(3, result, "List length incorrect");
    TEST_ASSERT_EQUAL(10, head->data);

    // Cleanup
    ll_destroy(head);
}


/**
 * Create four item list and delete tail
 */
void test_four_tail(void) {
    struct ll_node *head = ll_create(10);
    ll_append(head, 20);
    ll_append(head, 30);
    ll_append(head, 40);

    head = ll_delete(head, 40);

    TEST_ASSERT_NOT_NULL(head);
    int result = ll_size(head);
    TEST_ASSERT_EQUAL_MESSAGE(3, result, "List length incorrect");
    TEST_ASSERT_EQUAL(10, head->data);

    // Cleanup
    ll_destroy(head);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_one);

    RUN_TEST(test_two_head);
    RUN_TEST(test_two_tail);

    RUN_TEST(test_four_head);
    RUN_TEST(test_four_middle);
    RUN_TEST(test_four_tail);

    return UNITY_END();
}
