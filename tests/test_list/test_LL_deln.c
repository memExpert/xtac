#include "unity.h"
#include "list.h"

static LL_base* list = NULL;
static arr[] = {1, 2, 3, 4, 5};

void setUp(void) {
    list = LL_create_base(sizeof(int));
}

void tearDown(void) {
    LL_free(&list);
}

void test_LL_deln(void) {
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    int temp = 0;
    for(size_t i = 0; i < arr_size; i++){
        LL_pushb(list, arr + i);
    }
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_deln(list, &temp, 3));
    TEST_ASSERT_EQUAL_INT(list->len, arr_size - 1);
    TEST_ASSERT_EQUAL_INT(arr[3], temp);
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_deln(list, &temp, 0));
    TEST_ASSERT_EQUAL_INT(list->len, arr_size - 1);
    TEST_ASSERT_EQUAL_INT(arr[0], temp);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_LL_deln);
    return UNITY_END();
}