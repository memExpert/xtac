/*******************************************************************************
 * @file list.c
 * @author Maksim Hanchar (Maksim.Hanchar@belcommunmash.by)
 * @brief 
 * @version 0.1
 * @date 08-08-2024
 * 
 * @copyright Copyright (c) 2024
 * 
*******************************************************************************/

#include "../includes/list2.h"
#include <inttypes.h>
#include <malloc.h>
#include <string.h>

#include <stdio.h> /* temporary */



LL_item* LL_init_item(void) {
    LL_item* item = (LL_item*) malloc(sizeof(LL_item));
    if(!item) return NULL;

    item->data = NULL;
    item->next = NULL;

    return item;
}

void LL_free_item(LL_item** item) {
    if(!(item && *item)) return;

    free((*item)->data);
    free(*item);
    *item = NULL;
}

LL_item* LL_create_item(void* data, size_t size_of_data) {
    if(!data) return NULL;          /* If data ptr is NULL */

    LL_item* item = LL_init_item(); /* Trying to initialize memory for new item object */
    if(!item) return NULL;          /* If something went wrong while initialization    */
    
    item->data = malloc(size_of_data); /* Trying to allocate memory for item data      */
    if(!(item->data)){                 /* If something went wrong while memory allocate*/
        LL_free_item(&item);           /* free memory of item and return NULL; */
        return NULL;
    }

    memmove(item->data, data, size_of_data);/* Copy values in *data to *(item->data) */
    return item;                            /* return created item                   */
}

/*******************************************************************************
 * @brief LL_addf is function that add new list node to forward. 
 *
 * @param current 
 * @param data 
 * @param size_of_data 
 * @return true if all ok
 * @return false if can't memorry allocate
*******************************************************************************/
bool LL_addf(LL_item** current, void* data, size_t size_of_data) {
    LL_item*  new_item = LL_create_item(data, size_of_data);
    if(!new_item) return false;

    new_item->next = *current;
    (*current) = new_item;
    return true;
}

bool LL_addb(LL_item** current, void*data, size_t size_of_data) {
    if(!current) return false;

    LL_item* new_item = LL_create_item(data, size_of_data);
    if(!new_item) return false;

    (*current)->next = new_item;
    return true;
}

LL_base* LL_init_base(size_t data_size) {
    LL_base* list_base = (LL_base*) malloc (sizeof(LL_base));
    if(!list_base) return NULL;

    list_base->data_sz = data_size;
    list_base->first   = malloc(sizeof(LL_item**));
    list_base->last    = list_base->first;
    list_base->len     = 0;

    return list_base;
}

void LL_free_list_from(LL_item** current) {
    printf("LL_free_list_from \n");
    if(!current || !(*current)) {
        return;
    }
    LL_free_list_from(&((*current)->next));
    LL_free_item(current);
    *current = NULL;
}

void LL_free_base(LL_base** list_base) {
    if(!(list_base && *list_base)) return;
    
    LL_free_list_from((*list_base)->first);
    free((*list_base)->first);
    free((*list_base)->last);
    free(*list_base);
    *list_base = NULL;
}

static bool LL_inc_len (LL_base* list_base) {
    if(list_base && list_base->len < SIZE_MAX) {
        list_base->len++;
        return true;
    } else {
        return false;
    }
}

static bool LL_dec_len (LL_base* list_base) {
    if(list_base && list_base->len > 0) {
        list_base->len--;
        return true;
    } else {
        return false;
    }
}

LL_EXEC_RESULT LL_pushf(LL_base* list, void* data) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;

    if(LL_inc_len(list)) {
        if(LL_addf(list->first, data, list->data_sz)) {
            return LL_EXEC_SUCCESS;
        } else {
            LL_dec_len(list);
            return LL_EXEC_NO_MEMORY;
        }
    } else {
        return LL_EXEC_LIST_FULL;
    }
}

LL_EXEC_RESULT LL_popf(LL_base* list, void* data) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;

    if(LL_dec_len(list)) {
        LL_item* tmp_ptr = *(list->first);
        *(list->first) = tmp_ptr->next;
        memmove(data, tmp_ptr->data, list->data_sz);
        LL_free_item(&tmp_ptr);
    } else {
        return LL_EXEC_LIST_EMPTY;
    }
    return LL_EXEC_SUCCESS;
}



int main(void) {
    int arr[] = {11,22,33};
    int temp_int = 0;
    LL_base* tlist = LL_init_base(sizeof(int));
    for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
        LL_pushf(tlist, &(arr[i]));
        printf("List len: %"PRId64"\n", tlist->len);
    }
    LL_free_base(&tlist);
    return 0;
    for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); i++){
        LL_popf(tlist, &temp_int);
        printf("List len: %"PRId64", temp_int: %d\n", tlist->len, temp_int);
    }

    return 0;
}