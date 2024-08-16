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

void test_popb(void) {
    int temp = 0;
    for(size_t i = 0; LL_popb(list, &temp) != LL_EXEC_LIST_EMPTY && i < arr_size; i++) {
        TEST_ASSERT_EQUAL_INT_MESSAGE(arr[arr_size - (i + 1)], temp, "arr[i] != temp");
        TEST_ASSERT_EQUAL_INT_MESSAGE(arr_size - (i + 1), list->len, "list->len is wrong");
    }
    TEST_ASSERT_NULL(*(list->first));
    TEST_ASSERT_NULL(*(list->last));
    TEST_ASSERT_EQUAL_INT(0, list->len);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_popb);
    return UNITY_END();
}