#include "unity.h"
#include "htab.h"


static HT_base* ht = NULL;

void setUp(void) {
}

void tearDown(void) {
    HT_free(ht);
}

void test_HT_create(void) {
    ht = HT_create();
    
    TEST_ASSERT_NOT_NULL_MESSAGE(ht, "Hash table isn't allocated.");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_HT_create);
    return UNITY_END();
}