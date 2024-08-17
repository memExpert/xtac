#include "unity.h"
#include "list.h"

static LL_base* list = NULL;
static int arr[] = {1, 2, 3, 4, 5};
size_t arr_size = sizeof(arr) / sizeof(*arr);

void setUp(void) {
    list = LL_create_base(sizeof(int));
    for(size_t i = 0; i < arr_size; i++) {
        LL_pushb(list, arr + i);
    }
}

void tearDown(void) {
    LL_free(&list);
}

void test_popf(void) {
    int temp = 0;
    for(size_t i = arr_size - 1; LL_popf(list, &temp) != LL_EXEC_LIST_EMPTY; i--) {
        TEST_ASSERT_EQUAL_INT(arr[arr_size - (i + 1)], temp);
        TEST_ASSERT_EQUAL_INT(i, list->len);
    }
    TEST_ASSERT_NULL(*(list->first));
    TEST_ASSERT_NULL(*(list->last));
    TEST_ASSERT_EQUAL_INT(0, list->len);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_popf);
    return UNITY_END();
}