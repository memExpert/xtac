#include "unity.h"
#include "htab.h"


static HT_base* ht = NULL;

void setUp(void) {
    ht = HT_create();
}

void tearDown(void) {
}

void test_HT_free(void) {
    TEST_ASSERT_NOT_NULL_MESSAGE(ht, "Hash table isn't allocated.");
    HT_free(ht);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_HT_free);
    return UNITY_END();
}