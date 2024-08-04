#include <inttypes.h>
#include <stdio.h>
#include "../includes/list.h"
#include <stdlib.h>
#include <time.h>

#define TEST_ARRAY_SIZE 128

typedef enum {
    int8,
    int16,
    int32,
    int64,
    flt,
    dbl
} TYPE_ENUM;

bool init_test_array(void* const array, size_t arr_size, size_t element_size) {
    void* ptr = array;
    if(!element_size) return false;
    size_t rand_num = 0;
    srand(time(NULL));
    for(size_t i = 0; i < arr_size; i++){
        rand_num = rand();
        for(size_t j = 0; j < element_size; j++) {
            *((int8_t*)(array) + (i * element_size) + j) = *((int8_t*)(&rand_num) + j);
        }
    }
    return true;
}


int32_t main(void) {
    bool init_result = false;
    int32_t int32_array[TEST_ARRAY_SIZE] = {0};
    if(!init_test_array(int32_array, TEST_ARRAY_SIZE, sizeof(int32_t))) {
        fprintf(stderr, "Array is not initialized.\n");
        return 1;
    }
    LIST* new_list = LIST_init(int32_array, sizeof(int32_t));
    for(size_t i = 1; i < TEST_ARRAY_SIZE; i++){
        LIST_addf(&new_list, int32_array + i, sizeof(int32_t));
    }
}