#include "unity.h"
#include "list.h"

static LL_base* list = NULL;

void setUp(void) {
}

void tearDown(void) {
    LL_free(&list);
}

void test_create_base(void) {
    list = LL_create_base(sizeof(int));
    
    TEST_ASSERT_NOT_NULL_MESSAGE(list, "List base isn't allocated.");
    TEST_ASSERT_NOT_NULL_MESSAGE(list->first,"List 'first' field isn't allocated");
    TEST_ASSERT_NOT_NULL_MESSAGE(list->last, "List 'last' field isn't allocated");
    TEST_ASSERT_EQUAL_size_t_MESSAGE(0, list->len, "List init len not equal 0");
    TEST_ASSERT_EQUAL_size_t_MESSAGE(sizeof(int), list->data_sz, "Wrong list data size");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LL_READY, list->state, "Wrong list state");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_create_base);
    return UNITY_END();
}