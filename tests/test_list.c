#if 0
#include "../includes/list.h"
#include "inttypes.h"
#include <time.h>
#include <stdio.h>


int main(void) {
    clock_t start_time;
    clock_t push_time;
    clock_t end_time;
    start_time = clock();
    //int arr[] = {36,178,438,780,992,763,172,742,137,66,389,457,620,966,580,318,529,996,810,203,522,815,688,186,214,17,291,478,21,825,257,643,677,440,811,722,171,448,534,115,286,78,777,49,232,758,583,702,161,408,100,832,778,84,159,798,396,809,116,999,176,234,420,276,245,166,519,450,60,735,695,388,315,960,162,848,987,884,338,415,88,540,914,913,591,713,24,852,212,455,375,157,11,208,746,195,102,703,230,57,634,313,204,843,423,475,373,784,601,445,727,362,819,167,789,991,776,672,640,119,626,505,772,149,67,603,165,932,169,99,553,227,462,836,339,452,818,968,927,616,279,530,380,595,578,558,716,822,724,219,258,602,282,154,732,207,156,278,378,800,277,573,889,543,211,306,689,34,555,579,952,164,508,898,43,581,101,679,609,299,47,565,506,795,938,931,970,817,910,285,202,673,304,515,629,980,191,139,726,855,261,289,842,405,237,384,133,663,528,255,467,25,687,404,50,476,264,632,627,249,526,764,485,721,569,621,923,805,297,326,859,168,638,691,624,814,215,357,906,130,886,487,773,741,464,74,8,151,518,52,706,327,187,894,2,81,403,893,226,899,46,520,305,835,747,941,572,660,692,259,443,155,803,91,474,837,288,480,218,905,446,588,398,830,16,775,439,385,281,422,678,146,883,135,694,371,739,386,23,12,582,717,759,402,263,704,720,144,847,829,42,417,671,45,370,937,497,682,26,930,196,5,652,412,456,470,441,170,686,323,300,348,783,428,606,75,977,915,834,645,869,394,900,97,283,831,138,895,920,382,274,235,107,749,390,845,364,545,360,723,953,701,801,391,857,294,108,63,965,669,503,55,121,192,760,650,369,303,409,648,482,340,637,269,897,426,854,653,356,768,542,909,928,617,570,972,71,223,878,491,96,872,979,471,361,496,908,458,867,163,523,876,500,220,347,685,188,862,56,502,105,4,797,599,969,959,416,590,70,463,792,510,492,330,887,902,684,20,849,770,711,298,290,393,490,761,365,610,958,395,158,561,861,216,916,174,901,41,516,59,864,656,332,320,309,317,268,728,552,655,301,430,73,586,696,944,86,734,333,675,328,823,80,262,311,592,964,217,10,72,345,625,114,493,725,62,737,949,468,577,110,816,539,27,484,881,751,229,820,994,998,933,296,752,273,873,134,224,559,631,397,368,600,381,615,765,131,350,840,544,533,925,997,957,537,400,179,209,435,82,674,39,460,494,922,844,956,806,788,594,587,785,194,718,512,647,654,781,1,295,662,472,670,284,919,501,649,190,425,486,29,856,38,541,924,79,292,181,605,147,312,200,427,143,434,3,228,879,250,118,307,198,538,940,511,955,676,556,175,451,308,127,549,667,324,766,790,808,387,507,513,92,366,641,705,851,921,658,407,636,981,753,963,951,846,875,993,917,447,562,882,248,18,93,128,199,453,912,37,334,548,623,372,939,418,630,885,598,794,65,184,547,14,112,51,644,488,335,260,514,827,657,863,731,193,406,7,740,985,454,469,77,239,31,374,525,68,466,903,465,153,976,270,499,926,123,967,280,738,87,94,536,521,221,504,251,664,140,633,225,253,978,642,986,444,354,336,666,971,839,576,477,95,28,729,132,611,136,111,205,341,865,197,419,962,551,826,535,424,983,481,160,411,117,44,870,890,974,911,509,708,824,907,473,748,316,242,639,150,681,431,177,709,83,53,888,247,585,557,314,495,989,254,567,619,113,349,593,745,353,546,152,597,413,771,201,319,946,607,755,934,367,524,614,358,945,437,782,714,517,608,180,990,612,483,942,377,267,479,807,321,715,574,142,756,584,589,531,337,802,786,346,896,948,947,363,58,383,325,874,275,950,9,618,757,399,982,256,189,54,236,13,754,858,401,787,841,90,693,342,310,866,183,860,40,730,712,293,604,736,252,410,762,796,853,61,975,833,532,266,244,568,774,812,935,973,103,683,622,124,659,961,109,564,719,22,988,392,222,628,210,459,376,813,302,698,120,89,596,421,246,563,449,700,351,791,838,954,793,680,904,943,343,206,30,575,33,733,271,804,182,828,892,106,690,442,129,35,272,560,433,6,984,489,779,429,19,750,566,651,550,850,331,821,352,125,329,32,918,697,287,173,635,707,355,379,122,15,240,104,868,613,661,231,359,891,69,646,769,64,98,527,238,699,76,141,213,744,432,265,1000,241,936,799,880,668,710,233,995,148,414,322,767,743,243,461,877,85,344,185,929,126,145,871,498,436,665,554,571,48};
    int temp_int = 0;
    int arr[] = {1, 2, 3, 4, 5};
    LL_base* tlist = LL_create_base(sizeof(int));
    for(size_t j = 0; j < 1; j++){
        for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
            LL_pushf(tlist, &(arr[i]));
//            printf("item i = %"PRId64" dig = %d\n", tlist->len, arr[i]);
        }
/*
        for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
            LL_pushb(tlist, &(arr[i]));
//            printf("item i = %"PRId64" dig = %d\n", tlist->len, arr[i]);
        }

        for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
            LL_pushf(tlist, &(arr[i]));
//            printf("item i = %"PRId64" dig = %d\n", tlist->len, arr[i]);
        }
        for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
            LL_pushb(tlist, &(arr[i]));
//            printf("item i = %"PRId64" dig = %d\n", tlist->len, arr[i]);
        }
*/
    }
    int tmp = 0;
    printf("LL_getn return %d\n", LL_getn(tlist, &tmp, 5));
    printf("item3->data = %d\n", tmp);
    printf("len = %"PRId64"\n", tlist->len);

    push_time = clock();
    while(LL_popb(tlist, &temp_int) != LL_EXEC_LIST_EMPTY) {
//            printf("List len: %"PRId64", temp_int: %d\n", tlist->len, temp_int);
    }
    end_time = clock();
    double push_time_taken = (double)(push_time - start_time) / (double)(CLOCKS_PER_SEC);
    double pop_time_taken = (double)(end_time - push_time) / (double)(CLOCKS_PER_SEC);
    printf("Push time: %lf sec\n", push_time_taken);
    printf("Pop  time: %lf sec\n", pop_time_taken);

    /*
    for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
        LL_popb(tlist, &temp_int);
        printf("List len: %"PRId64", temp_int: %d\n", tlist->len, temp_int);
    }

    for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
        LL_popf(tlist, &temp_int);
        printf("List len: %"PRId64", temp_int: %d\n", tlist->len, temp_int);
    }
    */
    printf("%d, %d\n", *(tlist->first) == NULL, *(tlist->last) == NULL);
//    LL_free(&tlist);
    return 0;
}
#endif

#include "unity.h"
#include "list.h"

static LL_base* list = NULL;
//static int arr[] = {36,178,438,780,992,763,172,742,137,66,389,457,620,966,580,318,529,996,810,203,522,815,688,186,214,17,291,478,21,825,257,643,677,440,811,722,171,448,534,115,286,78,777,49,232,758,583,702,161,408,100,832,778,84,159,798,396,809,116,999,176,234,420,276,245,166,519,450,60,735,695,388,315,960,162,848,987,884,338,415,88,540,914,913,591,713,24,852,212,455,375,157,11,208,746,195,102,703,230,57,634,313,204,843,423,475,373,784,601,445,727,362,819,167,789,991,776,672,640,119,626,505,772,149,67,603,165,932,169,99,553,227,462,836,339,452,818,968,927,616,279,530,380,595,578,558,716,822,724,219,258,602,282,154,732,207,156,278,378,800,277,573,889,543,211,306,689,34,555,579,952,164,508,898,43,581,101,679,609,299,47,565,506,795,938,931,970,817,910,285,202,673,304,515,629,980,191,139,726,855,261,289,842,405,237,384,133,663,528,255,467,25,687,404,50,476,264,632,627,249,526,764,485,721,569,621,923,805,297,326,859,168,638,691,624,814,215,357,906,130,886,487,773,741,464,74,8,151,518,52,706,327,187,894,2,81,403,893,226,899,46,520,305,835,747,941,572,660,692,259,443,155,803,91,474,837,288,480,218,905,446,588,398,830,16,775,439,385,281,422,678,146,883,135,694,371,739,386,23,12,582,717,759,402,263,704,720,144,847,829,42,417,671,45,370,937,497,682,26,930,196,5,652,412,456,470,441,170,686,323,300,348,783,428,606,75,977,915,834,645,869,394,900,97,283,831,138,895,920,382,274,235,107,749,390,845,364,545,360,723,953,701,801,391,857,294,108,63,965,669,503,55,121,192,760,650,369,303,409,648,482,340,637,269,897,426,854,653,356,768,542,909,928,617,570,972,71,223,878,491,96,872,979,471,361,496,908,458,867,163,523,876,500,220,347,685,188,862,56,502,105,4,797,599,969,959,416,590,70,463,792,510,492,330,887,902,684,20,849,770,711,298,290,393,490,761,365,610,958,395,158,561,861,216,916,174,901,41,516,59,864,656,332,320,309,317,268,728,552,655,301,430,73,586,696,944,86,734,333,675,328,823,80,262,311,592,964,217,10,72,345,625,114,493,725,62,737,949,468,577,110,816,539,27,484,881,751,229,820,994,998,933,296,752,273,873,134,224,559,631,397,368,600,381,615,765,131,350,840,544,533,925,997,957,537,400,179,209,435,82,674,39,460,494,922,844,956,806,788,594,587,785,194,718,512,647,654,781,1,295,662,472,670,284,919,501,649,190,425,486,29,856,38,541,924,79,292,181,605,147,312,200,427,143,434,3,228,879,250,118,307,198,538,940,511,955,676,556,175,451,308,127,549,667,324,766,790,808,387,507,513,92,366,641,705,851,921,658,407,636,981,753,963,951,846,875,993,917,447,562,882,248,18,93,128,199,453,912,37,334,548,623,372,939,418,630,885,598,794,65,184,547,14,112,51,644,488,335,260,514,827,657,863,731,193,406,7,740,985,454,469,77,239,31,374,525,68,466,903,465,153,976,270,499,926,123,967,280,738,87,94,536,521,221,504,251,664,140,633,225,253,978,642,986,444,354,336,666,971,839,576,477,95,28,729,132,611,136,111,205,341,865,197,419,962,551,826,535,424,983,481,160,411,117,44,870,890,974,911,509,708,824,907,473,748,316,242,639,150,681,431,177,709,83,53,888,247,585,557,314,495,989,254,567,619,113,349,593,745,353,546,152,597,413,771,201,319,946,607,755,934,367,524,614,358,945,437,782,714,517,608,180,990,612,483,942,377,267,479,807,321,715,574,142,756,584,589,531,337,802,786,346,896,948,947,363,58,383,325,874,275,950,9,618,757,399,982,256,189,54,236,13,754,858,401,787,841,90,693,342,310,866,183,860,40,730,712,293,604,736,252,410,762,796,853,61,975,833,532,266,244,568,774,812,935,973,103,683,622,124,659,961,109,564,719,22,988,392,222,628,210,459,376,813,302,698,120,89,596,421,246,563,449,700,351,791,838,954,793,680,904,943,343,206,30,575,33,733,271,804,182,828,892,106,690,442,129,35,272,560,433,6,984,489,779,429,19,750,566,651,550,850,331,821,352,125,329,32,918,697,287,173,635,707,355,379,122,15,240,104,868,613,661,231,359,891,69,646,769,64,98,527,238,699,76,141,213,744,432,265,1000,241,936,799,880,668,710,233,995,148,414,322,767,743,243,461,877,85,344,185,929,126,145,871,498,436,665,554,571,48};
static int arr[5] = {1, 2, 3, 4, 5};
void setUp(void) {
    list = LL_create_base(sizeof(int));
}

void tearDown(void) {
    while(LL_popf(list, NULL) != LL_EXEC_LIST_EMPTY);
}

void test_create_base(void) {
    LL_base* list = NULL;
    list = LL_create_base(sizeof(int));
    
    TEST_ASSERT_NOT_NULL_MESSAGE(list, "List base isn't allocated.");
    TEST_ASSERT_NOT_NULL_MESSAGE(list->first,"List 'first' field isn't allocated");
    TEST_ASSERT_NOT_NULL_MESSAGE(list->last, "List 'last' field isn't allocated");
    TEST_ASSERT_EQUAL_size_t_MESSAGE(0, list->len, "List init len not equal 0");
    TEST_ASSERT_EQUAL_size_t_MESSAGE(sizeof(int), list->data_sz, "Wrong list data size");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LL_READY, list->state, "Wrong list state");
}

void test_pushf(void) {
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_pushf(list, arr));
    TEST_ASSERT_EQUAL_INT(arr[0], *(int*)((*(list->first))->data));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_pushf(list, arr + 1));
    TEST_ASSERT_EQUAL_INT(arr[1], *(int*)((*(list->first))->data));
    TEST_ASSERT_EQUAL_INT(2, list->len);
}

void test_pushb(void){
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_pushb(list, arr));
    TEST_ASSERT_EQUAL_INT(arr[0], *(int*)((*(list->first))->data));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_pushb(list, arr + 1));
    TEST_ASSERT_EQUAL_INT(arr[1], *(int*)((*(list->first))->next->data));
    TEST_ASSERT_EQUAL_INT(2, list->len);
}

void test_getn(void) {
    int data = 0;
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    for(size_t i = 0; i < arr_size; i++){
        LL_pushb(list, arr + i);
    }
    
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_getn(list, &data, 0));
    TEST_ASSERT_EQUAL_INT(arr[0], data);
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_getn(list, &data, 1));
    TEST_ASSERT_EQUAL_INT(arr[1], data);
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_getn(list, &data, 3));
    TEST_ASSERT_EQUAL_INT(arr[3], data);
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_getn(list, &data, 1));
    TEST_ASSERT_EQUAL_INT(arr[1], data);
    TEST_ASSERT_EQUAL_INT(LL_EXEC_INDEX_OUT_OF_RANGE, LL_getn(list, &data, arr_size));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_NULL_BASE_PTR, LL_getn(NULL, &data, arr_size));
    LL_base* tmp_list = LL_create_base(sizeof(int));
    TEST_ASSERT_EQUAL_INT(LL_EXEC_LIST_EMPTY, LL_getn(tmp_list, &data, 3));
    LL_free(&tmp_list);
}

void test_popf(void) {
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    int temp = 0;
    for(size_t i = 0; i < arr_size; i++){
        LL_pushf(list, arr + i);
    }
    for(size_t i = arr_size - 1; LL_popf(list, &temp) != LL_EXEC_LIST_EMPTY && i > 0; i--) {
        TEST_ASSERT_EQUAL_INT(arr[i], temp);
        TEST_ASSERT_EQUAL_INT(i, list->len);
    }
    TEST_ASSERT_NULL(*(list->first));
    TEST_ASSERT_NULL(*(list->last));
    TEST_ASSERT_EQUAL_INT(0, list->len);
}


void test_popb(void) {
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    int temp = 0;
    for(size_t i = 0; i < arr_size; i++){
        LL_pushf(list, arr + i);
    }
    for(size_t i = 0; LL_popb(list, &temp) != LL_EXEC_LIST_EMPTY && i < arr_size; i++) {
        TEST_ASSERT_EQUAL_INT_MESSAGE(arr[i], temp, "arr[i] != temp");
        TEST_ASSERT_EQUAL_INT_MESSAGE(arr_size - (i + 1), list->len, "list->len is wrong");
    }
    TEST_ASSERT_NULL(*(list->first));
    TEST_ASSERT_NULL(*(list->last));
    TEST_ASSERT_EQUAL_INT(0, list->len);
}

void test_deln(void) {
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    int temp = 0;
    for(size_t i = 0; i < arr_size; i++){
        LL_pushb(list, arr + i);
    }
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_deln(list, &temp, 3));
    TEST_ASSERT_EQUAL_INT(list->len, arr_size - 1);
    TEST_ASSERT_EQUAL_INT(arr[3], temp);
}

void test_insn(void) {
    size_t arr_size = sizeof(arr) / sizeof(*arr);
    int temp = 0;
    for(size_t i = 0; i < arr_size; i++){
        LL_pushb(list, arr + i);
    }
    TEST_ASSERT_EQUAL_INT(LL_EXEC_SUCCESS, LL_insn(list, arr, 2));
    TEST_ASSERT_EQUAL_INT(arr_size + 1, list->len);
    LL_getn(list, &temp, 2);
    TEST_ASSERT_EQUAL_INT(arr[0], temp);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_create_base);
    RUN_TEST(test_pushf);
    RUN_TEST(test_pushb);
    RUN_TEST(test_getn);
    RUN_TEST(test_popf);
    RUN_TEST(test_popb);
    RUN_TEST(test_deln);
    RUN_TEST(test_insn);

    return UNITY_END();
}