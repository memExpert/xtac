#include "unity.h"
#include "list.h"

static LL_base* list = NULL;
static arr[] = {1, 2, 3, 4, 5};
size_t arr_size = sizeof(arr) / sizeof(*arr);

void setUp(void) {
    list = LL_create_base(sizeof(int));
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

void test_LL_insn(void) {
    int tmp = 0;
    int actual = -1;
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_insn(list, &tmp, 2));
    LL_getn(list, &actual, 2);
    TEST_ASSERT_EQUAL_INT(tmp, actual);
    TEST_ASSERT_EQUAL_INT(arr_size + 1, LL_length(list));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_INDEX_OUT_OF_RANGE, LL_insn(list, &tmp, 52));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_NO_DATA_PTR, LL_insn(list, NULL, 52));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_NULL_BASE_PTR, LL_insn(NULL, &tmp, 52));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_LL_insn);
    return UNITY_END();
}