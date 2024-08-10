/**
 * @file list.c
 * @author Hanchar Maksim (hancharmaksimq@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-09
 * 
 * @copyright Copyright (c) 2024 Hanchar Maksim
 * 
 */

#include "../../includes/list.h"
#include <inttypes.h>
#include <malloc.h>
#include <string.h>

#include <stdio.h> /* temporary */

#define LIST_CONTAIN_LAST_ITEM 1

size_t LL_length(const LL_base* list) {
    return list ? list->len : 0;
}

LL_state LL_get_state(const LL_base* list) {
    return list ? list->state : LL_NA;
}

static LL_item* LL_init_item(void) {
    LL_item* item = (LL_item*) malloc(sizeof(LL_item));
    if(!item) return NULL;

    item->data = NULL;
    item->next = NULL;

    return item;
}

static void LL_free_item(LL_item** item) {
    if(!(item && *item)) return;
    free((*item)->data);
    (*item)->next = NULL;
    (*item)->data = NULL;
    free(*item);
    *item = NULL;   
}

static LL_item* LL_create_item(const void* data, size_t size_of_data) {
    if(!data) return NULL;             /* If provided argument is NULL        */

    LL_item* item = LL_init_item();    /* Init memory for new item object     */
    if(!item) return NULL;
    
    item->data = malloc(size_of_data); /* Trying to get memory for item data  */
    if(!(item->data)) {                /* If something went wrong             */
        LL_free_item(&item);           /* free memory of item and return NULL */
        return NULL;
    }
    memmove(item->data, data, size_of_data);/* Copy *data to *(item->data)    */
    return item;                            /* return created item            */
}

/*
LL_item* LL_get_item(LL_base* list, size_t item_number) {
    if(!list || item_number >= LL_length(list)) return NULL;
    LL_item* item = list->first;
    if(item){
        for(size_t i = 0; i < item_number && item->next; i++) {
            item = item->next;
        }
    }
    return item;
}
*/

/*******************************************************************************
 * @brief LL_addf is function that add new list node to forward. 
 *
 * @param current 
 * @param data 
 * @param size_of_data 
 * @return true if all ok 
 * @return false if can't memorry allocate
*******************************************************************************/
static bool LL_addf(LL_item** current, const void* data, size_t size_of_data) {
    LL_item*  new_item = LL_create_item(data, size_of_data);
    if(!new_item) return false;

    new_item->next = *current;
    (*current) = new_item;
    return true;
}

static bool LL_addb(LL_item** current, const void* data, size_t size_of_data) {
    if(!current) return false;

    LL_item* new_item = LL_create_item(data, size_of_data);
    if(!new_item) return false;
    if(*current){
        (*current)->next = new_item;
    }
    (*current) = new_item;
    return true;
}

static LL_base* LL_alloc_base(void) {
    LL_base* list_base = (LL_base*) malloc (sizeof(LL_base));
    if(!list_base) return NULL;

    list_base->first = malloc(sizeof(LL_item**));
    if(!list_base->first) {
        free(list_base);
        return NULL;
    }
    list_base->last = malloc(sizeof(LL_item**));
    if(!list_base->last) {
        free(list_base->first);
        free(list_base);
        return NULL;
    }
    return list_base;
}

LL_base* LL_create_base(size_t data_size) {
    LL_base* list_base = LL_alloc_base();
    if (list_base) {
        list_base->data_sz = data_size;
        *(list_base->first) = NULL;
        *(list_base->last)  = NULL;
        list_base->state    = LL_READY;
        list_base->len      = 0;
    }
    return list_base;
}

static void LL_free_from(LL_item** current) {
    if(!current || !(*current)) {
        return;
    }
    LL_free_from(&((*current)->next));
    LL_free_item(current);
    *current = NULL;
}

void LL_free(LL_base** list_base) {
    if(!list_base || !*list_base) return;

    LL_free_from((*list_base)->first);
    LL_base* tmp = *list_base;
    *list_base = NULL;

    free(tmp->first);
    free(tmp->last);
    free(tmp);
}

LL_EXEC_RESULT LL_pushf(LL_base* list, const void* data) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;

    if(list->len < SIZE_MAX) {
        if(LL_addf(list->first, data, list->data_sz)) {
            list->len++;
            if(LL_length(list) == LIST_CONTAIN_LAST_ITEM) {
                *(list->last) = *(list->first);
            }
            return LL_EXEC_SUCCESS;
        } else return LL_EXEC_NO_MEMORY;    /* no memory for LL_item alloc */
    } else return LL_EXEC_LIST_FULL;        /* list length > SIZE_MAX      */
}

LL_EXEC_RESULT LL_pushb(LL_base* list, const void* data) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;

    if(list->len < SIZE_MAX) {
        if(LL_addb(list->last, data, list->data_sz)){
            list->len++;
            if(LL_length(list) == LIST_CONTAIN_LAST_ITEM) {
                *(list->first) = *(list->last);
            }
            return LL_EXEC_SUCCESS;
        } else return LL_EXEC_NO_MEMORY;    /* no memory for LL_item alloc */
    } else return LL_EXEC_LIST_FULL;        /* list length > SIZE_MAX      */
}

LL_EXEC_RESULT LL_popf(LL_base* list, void* data) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;

    if(*(list->first)) {
        memmove(data, (*(list->first))->data, list->data_sz);
        LL_item* tmp_ptr = *(list->first);
        if(LL_length(list) == LIST_CONTAIN_LAST_ITEM) {
            LL_free_item(list->first);
            *(list->last) = *(list->first);
        } else {
            *(list->first) = (*(list->first))->next;
            LL_free_item(&tmp_ptr);
        }
        list->len--;
        return LL_EXEC_SUCCESS;
    } else return LL_EXEC_LIST_EMPTY;
}


LL_EXEC_RESULT LL_popb(LL_base* list, void* data) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;

    if(*(list->first)) {
        memmove(data, (*(list->last))->data, list->data_sz);
        LL_item* tmp_ptr  = *(list->first);
        LL_item* tmp_ptr2 = *(list->first);
        for(size_t i = 0; tmp_ptr; tmp_ptr = tmp_ptr->next, i++){
            if(i > 1) {
                tmp_ptr2 = tmp_ptr2->next;
            }
        }
        *(list->last) = tmp_ptr2;
        if(LL_length(list) == LIST_CONTAIN_LAST_ITEM) {
            LL_free_item(list->first);
            *(list->last) = *(list->first);
        } else {
            LL_free_item(&((*(list->last))->next));
        }
        list->len--;
    } else return LL_EXEC_LIST_EMPTY;
    return LL_EXEC_SUCCESS;
}


#include <time.h>
int main(void) {
    clock_t start_time;
    clock_t push_time;
    clock_t end_time;
    start_time = clock();
    int arr[] = {36,178,438,780,992,763,172,742,137,66,389,457,620,966,580,318,529,996,810,203,522,815,688,186,214,17,291,478,21,825,257,643,677,440,811,722,171,448,534,115,286,78,777,49,232,758,583,702,161,408,100,832,778,84,159,798,396,809,116,999,176,234,420,276,245,166,519,450,60,735,695,388,315,960,162,848,987,884,338,415,88,540,914,913,591,713,24,852,212,455,375,157,11,208,746,195,102,703,230,57,634,313,204,843,423,475,373,784,601,445,727,362,819,167,789,991,776,672,640,119,626,505,772,149,67,603,165,932,169,99,553,227,462,836,339,452,818,968,927,616,279,530,380,595,578,558,716,822,724,219,258,602,282,154,732,207,156,278,378,800,277,573,889,543,211,306,689,34,555,579,952,164,508,898,43,581,101,679,609,299,47,565,506,795,938,931,970,817,910,285,202,673,304,515,629,980,191,139,726,855,261,289,842,405,237,384,133,663,528,255,467,25,687,404,50,476,264,632,627,249,526,764,485,721,569,621,923,805,297,326,859,168,638,691,624,814,215,357,906,130,886,487,773,741,464,74,8,151,518,52,706,327,187,894,2,81,403,893,226,899,46,520,305,835,747,941,572,660,692,259,443,155,803,91,474,837,288,480,218,905,446,588,398,830,16,775,439,385,281,422,678,146,883,135,694,371,739,386,23,12,582,717,759,402,263,704,720,144,847,829,42,417,671,45,370,937,497,682,26,930,196,5,652,412,456,470,441,170,686,323,300,348,783,428,606,75,977,915,834,645,869,394,900,97,283,831,138,895,920,382,274,235,107,749,390,845,364,545,360,723,953,701,801,391,857,294,108,63,965,669,503,55,121,192,760,650,369,303,409,648,482,340,637,269,897,426,854,653,356,768,542,909,928,617,570,972,71,223,878,491,96,872,979,471,361,496,908,458,867,163,523,876,500,220,347,685,188,862,56,502,105,4,797,599,969,959,416,590,70,463,792,510,492,330,887,902,684,20,849,770,711,298,290,393,490,761,365,610,958,395,158,561,861,216,916,174,901,41,516,59,864,656,332,320,309,317,268,728,552,655,301,430,73,586,696,944,86,734,333,675,328,823,80,262,311,592,964,217,10,72,345,625,114,493,725,62,737,949,468,577,110,816,539,27,484,881,751,229,820,994,998,933,296,752,273,873,134,224,559,631,397,368,600,381,615,765,131,350,840,544,533,925,997,957,537,400,179,209,435,82,674,39,460,494,922,844,956,806,788,594,587,785,194,718,512,647,654,781,1,295,662,472,670,284,919,501,649,190,425,486,29,856,38,541,924,79,292,181,605,147,312,200,427,143,434,3,228,879,250,118,307,198,538,940,511,955,676,556,175,451,308,127,549,667,324,766,790,808,387,507,513,92,366,641,705,851,921,658,407,636,981,753,963,951,846,875,993,917,447,562,882,248,18,93,128,199,453,912,37,334,548,623,372,939,418,630,885,598,794,65,184,547,14,112,51,644,488,335,260,514,827,657,863,731,193,406,7,740,985,454,469,77,239,31,374,525,68,466,903,465,153,976,270,499,926,123,967,280,738,87,94,536,521,221,504,251,664,140,633,225,253,978,642,986,444,354,336,666,971,839,576,477,95,28,729,132,611,136,111,205,341,865,197,419,962,551,826,535,424,983,481,160,411,117,44,870,890,974,911,509,708,824,907,473,748,316,242,639,150,681,431,177,709,83,53,888,247,585,557,314,495,989,254,567,619,113,349,593,745,353,546,152,597,413,771,201,319,946,607,755,934,367,524,614,358,945,437,782,714,517,608,180,990,612,483,942,377,267,479,807,321,715,574,142,756,584,589,531,337,802,786,346,896,948,947,363,58,383,325,874,275,950,9,618,757,399,982,256,189,54,236,13,754,858,401,787,841,90,693,342,310,866,183,860,40,730,712,293,604,736,252,410,762,796,853,61,975,833,532,266,244,568,774,812,935,973,103,683,622,124,659,961,109,564,719,22,988,392,222,628,210,459,376,813,302,698,120,89,596,421,246,563,449,700,351,791,838,954,793,680,904,943,343,206,30,575,33,733,271,804,182,828,892,106,690,442,129,35,272,560,433,6,984,489,779,429,19,750,566,651,550,850,331,821,352,125,329,32,918,697,287,173,635,707,355,379,122,15,240,104,868,613,661,231,359,891,69,646,769,64,98,527,238,699,76,141,213,744,432,265,1000,241,936,799,880,668,710,233,995,148,414,322,767,743,243,461,877,85,344,185,929,126,145,871,498,436,665,554,571,48};
    int temp_int = 0;
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

#undef LIST_CONTAIN_LAST_ITEM
