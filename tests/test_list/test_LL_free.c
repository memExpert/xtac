#include "unity.h"
#include "list.h"

static LL_base* list = NULL;
static int arr[] = {1, 2, 3, 4, 5};

void setUp(void) {
    list = LL_create_base(sizeof(int));
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    for(size_t i = 0; i < arr_size; i++) {
        LL_pushb(list, arr + i);
    }
}

void tearDown(void) {
    LL_free(&list);
}

void test_LL_free(void) {
    LL_free(&list);
    TEST_ASSERT_NULL(list);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_LL_free);
    return UNITY_END();
}