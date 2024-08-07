/**
 * @file list.c
 * @author Hanchar Maksim (pottermax2000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "../includes/list.h"
#include <inttypes.h>
#include <malloc.h>
#include <string.h>

/*******************************************************************************
 *                      STATIC FUNCTIONS DEFINITIONS                           *
 ******************************************************************************/
static void LL_item_free(LL_item* item) {
    if(item){
        free(item->data);
        free(item);
    }
}


static bool LL_inc_len(LL_base* list) {
    bool result = false;
    if(LL_list_len(list) < SIZE_MAX){
        list->len++;
        result = true;
    }
    return result;
}

static bool LL_dec_len(LL_base* list) {
    bool result = false;
    if(LL_list_len(list) > 0) {
        list->len--;
        result = true;
    }
    return result;
}


/*******************************************************************************
 *                      GLOBAL FUNCTIONS DEFINITIONS                           *
 ******************************************************************************/

size_t LL_list_len(const LL_base* list) {
    if(list) {
        return list->len;
    } else {
        return 0;
    }
}

LL_base* LL_list_init (size_t data_size) {
    LL_base *list = (LL_base*) malloc(sizeof(LL_base));
    if(list) {
        list->data_sz = data_size;
        list->first = NULL;
        list->last  = NULL;
        list->len = 0;
    }
    return list;
}

LL_item* LL_item_init (void) {
    LL_item* new_list_item = (LL_item*) malloc(sizeof(LL_item));
    if(new_list_item) {
        new_list_item->data = NULL;
        new_list_item->next = NULL;
    }
    return new_list_item; 
}



bool LL_list_free (LL_base* list) {
    bool isFree = false;
    size_t garbage = 0;
    if(list) {
        while (LL_popf(list, &garbage))
            ;
        free(list);
    } else {
        isFree = false;
    }
    return isFree;
}


bool LL_pushf (LL_base* list_base, const void *data) {

    if(!(list_base && data && LL_inc_len(list_base))) return false;
    LL_item* new_first = LL_item_init();

    if(!new_first) {
        LL_dec_len(list_base);
        return false;
    }
    
    new_first->data = malloc(list_base->data_sz);
    if(!new_first->data) {
        LL_dec_len(list_base);
        LL_item_free(new_first);
        return false;
    }

    memmove(new_first->data, data, list_base->data_sz);
    new_first->next = list_base->first;
    list_base->first = new_first;
    
    if(LL_list_len(list_base) == 1) {
        list_base->last = list_base->first;
    }

    return true;
}

bool LL_popf (LL_base* list_base, void *data) {
    LL_item* tmp = NULL;
    if(!list_base && !data)    return false;
    if(!LL_dec_len(list_base)) return false;
    tmp = list_base->first;
    if(tmp) {
        memmove(data, tmp->data, list_base->data_sz);
        list_base->first = tmp->next;
        LL_item_free(tmp);
    } else {
        LL_inc_len(list_base);
        return false;
    }
    return true;
}

bool LL_pushb (LL_base* list_base, void const *data) {
    if(!(list_base && data && LL_inc_len(list_base))) return false;
    LL_item* new_last = LL_item_init();

    if(!new_last) {
        LL_dec_len(list_base);
        return false;
    }

    new_last->data = malloc(list_base->data_sz);
    if(!new_last->data) {
        LL_dec_len(list_base);
        LL_item_free(new_last);
        return false;
    }

    memmove(new_last->data, data, list_base->data_sz);
    if(list_base->last) {
        list_base->last->next = new_last;
    }
    list_base->last = new_last;

    if(LL_list_len(list_base) == 1) {
        list_base->first = list_base->last;
    }

    return true;
}


/* error inside this function. Need tests */
bool LL_popb (LL_base* const list_base, void *data) {
    LL_item* tmp = NULL;

    if(!list_base && !data)    return false;
    if(!LL_dec_len(list_base)) return false;
    
    tmp = list_base->first;
    if(tmp) {
        memmove(data, list_base->last, list_base->data_sz);
        while(tmp->next != list_base->last){ /* tmp = [last] - 1*/
            tmp = tmp->next;
        }
        LL_item_free(list_base->last);
        tmp->next = NULL;
        list_base->last = tmp;
    } else {
        LL_inc_len(list_base);
        return false;
    }
    return true;
}



#define COUNT_OF(_x) (sizeof(_x) / sizeof(*_x))
#include <stdio.h>
int main(void) {
    int arr[] = {10,11,12};
    int result = 0;
    LL_base* list = LL_list_init(sizeof(int));
    if(!list) return 1;
    /*
    for(size_t i = 0; i < COUNT_OF(arr); i++){
        LL_pushf(list, (void*)(arr + i));
        printf("%"PRId64"\n", LL_list_len(list));
    }
    while(LL_popf(list, (void*)&result)) {
        printf("%d - %"PRId64"\n", result, LL_list_len(list));
    }
    printf("\n");
    */
    for(size_t i = 0; i < COUNT_OF(arr); i++){
        LL_pushb(list, (void*)(arr + i));
        printf("%"PRId64"\n", LL_list_len(list));
    }
    while(LL_popb(list, (void*)&result)) {
        printf("%d - %"PRId64"\n", result, LL_list_len(list));
    }
    printf("%d - %"PRId64"\n", result, LL_list_len(list));
    printf("\n");
    return 0;
}