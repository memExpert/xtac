#include "unity.h"
#include "list.h"

static LL_base* list = NULL;
static arr[] = {1, 2, 3, 4, 5};

void setUp(void) {
    list = LL_create_base(sizeof(int));
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    for(size_t i = 0; i < arr_size; i++) {
        LL_pushb(list, arr + i);
    }
}

void tearDown(void) {
    while(LL_popf(list, NULL) != LL_EXEC_LIST_EMPTY);
    free(list->first);
    free(list->last);
    free(list);
    list = NULL;
}

void test_LL_getn(void) {
    int tmp = 0;
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_getn(list, &tmp, 2));
    TEST_ASSERT_EQUAL_INT(arr[2], tmp);
    TEST_ASSERT_EQUAL_INT(LL_EXEC_INDEX_OUT_OF_RANGE, LL_getn(list, &tmp, 52));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_NO_DATA_PTR, LL_getn(list, NULL, 52));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_NULL_BASE_PTR, LL_getn(NULL, &tmp, 52));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_LL_getn);
    return UNITY_END();
}