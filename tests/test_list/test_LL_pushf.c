#include "unity.h"
#include "list.h"

static LL_base* list = NULL;
static arr[] = {1, 2, 3, 4, 5};
size_t arr_size = sizeof(arr) / sizeof(*arr);

void setUp(void) {
    list = LL_create_base(sizeof(int));
}

void tearDown(void) {
    LL_free(&list);
}

void test_pushf(void) {
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_pushf(list, arr));
    TEST_ASSERT_EQUAL_INT(arr[0], *(int*)((*(list->first))->data));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_pushf(list, arr + 1));
    TEST_ASSERT_EQUAL_INT(arr[1], *(int*)((*(list->first))->data));
    TEST_ASSERT_EQUAL_INT(2, list->len);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_pushf);
    return UNITY_END();
}