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

enum {list_len_0 = 0};
enum {list_len_1 = 1};


/*******************************************************************************
 *                     STATIC FUNCTIONS IMPLEMENTATION 
 ******************************************************************************/
static LL_EXEC_RESULT LL_get_item(const LL_base* list, LL_item** dst, size_t pos) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;
    if(!*(list->first)) return LL_EXEC_LIST_EMPTY;
    if(pos >= LL_length(list)) return LL_EXEC_INDEX_OUT_OF_RANGE;

    LL_item* current = *(list->first);
    for(size_t i = 0; i < pos; i++) {
        current = current->next;
    }
    *dst = current;
    return LL_EXEC_SUCCESS;
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

/**
 * @brief LL_addf is function that add new list node to forward. 
 *
 * @param current 
 * @param data 
 * @param size_of_data 
 * @return true if all ok 
 * @return false if can't memorry allocate
 */
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

static void LL_free_from(LL_item** current) {
    if(!current || !(*current)) {
        return;
    }
    LL_free_from(&((*current)->next));
    LL_free_item(current);
    *current = NULL;
}

/*******************************************************************************
 *                              GLOBAL FUNCTIONS
 ******************************************************************************/


size_t LL_length(const LL_base* list) {
    return list ? list->len : list_len_0;
}

LL_state LL_get_state(const LL_base* list) {
    return list ? list->state : LL_NA;
}


LL_base* LL_create_base(size_t data_size) {
    LL_base* list_base = LL_alloc_base();
    if (list_base) {
        list_base->data_sz = data_size;
        *(list_base->first) = NULL;
        *(list_base->last)  = NULL;
        list_base->state    = LL_READY;
        list_base->len      = list_len_0;
    }
    return list_base;
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
            if(LL_length(list) == list_len_1) {
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
            if(LL_length(list) == list_len_1) {
                *(list->first) = *(list->last);
            }
            return LL_EXEC_SUCCESS;
        } else return LL_EXEC_NO_MEMORY;    /* no memory for LL_item alloc */
    } else return LL_EXEC_LIST_FULL;        /* list length > SIZE_MAX      */
}

LL_EXEC_RESULT LL_popf(LL_base* list, void* data) {
    if(!list) return LL_EXEC_NULL_BASE_PTR;

    if(*(list->first)) {
        if(data) {
            memmove(data, (*(list->first))->data, list->data_sz);
        }
        LL_item* tmp_ptr = *(list->first);
        if(LL_length(list) == list_len_1) {
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
        if(data) {
            memmove(data, (*(list->last))->data, list->data_sz);
        }
        LL_item* tmp_ptr  = *(list->first);
        for(size_t i = 0; tmp_ptr && tmp_ptr->next != *(list->last); i++) {
            tmp_ptr = tmp_ptr->next;
        }
        *(list->last) = tmp_ptr;
        if(LL_length(list) == list_len_1) {
            LL_free_item(list->first);
            *(list->last) = *(list->first);
        } else {
            LL_free_item(&((*(list->last))->next));
        }
        list->len--;
    } else return LL_EXEC_LIST_EMPTY;
    return LL_EXEC_SUCCESS;
}


LL_EXEC_RESULT LL_getn(const LL_base* list, void* data, size_t pos) {
    if(!data) return LL_EXEC_NO_DATA_PTR;
    LL_EXEC_RESULT result;
    LL_item* current = NULL;

    result = LL_get_item(list, &current, pos);
    if(result == LL_EXEC_SUCCESS) {
        memmove(data, current->data, list->data_sz);
    }
    return result;
}

LL_EXEC_RESULT LL_setn(LL_base* list, const void* data, size_t pos) {
    if(!data) return LL_EXEC_NO_DATA_PTR;
    LL_EXEC_RESULT result;
    LL_item* current = NULL;

    result = LL_get_item(list, &current, pos);
    if(result == LL_EXEC_SUCCESS) {
        memmove(current->data, data, list->data_sz);
    }
    return result;
}

LL_EXEC_RESULT LL_insn(LL_base* list, const void* data, size_t pos) {
    if(!data) return LL_EXEC_NO_DATA_PTR;
    LL_EXEC_RESULT result;
    LL_item* current = NULL;
    LL_item* precurrent = NULL;
    LL_item* new     = NULL;

    if(pos == 0) {
        return LL_pushf(list, data);
    } else if (pos == LL_length(list) - 1) {
        return LL_pushb(list, data);
    } else {
        result = LL_get_item(list, &current, pos);
        if(result == LL_EXEC_SUCCESS) {
            LL_get_item(list, &precurrent, pos - 1);
            new = LL_create_item(data, list->data_sz);
            if(!new) return LL_EXEC_NO_MEMORY;

            precurrent->next = new;
            new->next = current;
        }
    }
    return result;
}



LL_EXEC_RESULT LL_deln(LL_base* list, void* dst, size_t pos) {
    LL_EXEC_RESULT result;
    LL_item* current = NULL;
    LL_item* precurrent = NULL;

    if(pos == 0) {
        result = LL_popf(list, dst);
    } else if (pos == LL_length(list) - 1) {
        result = LL_popb(list, dst);
    } else {
        result = LL_get_item(list, &current, pos);
        
        if(result == LL_EXEC_SUCCESS) {
            if(dst) {
                memmove(dst, current->data, list->data_sz);
            }
            LL_get_item(list, &precurrent, pos - 1);
            precurrent->next = current->next;
            LL_free_item(&current);
            list->len--;
        }
    }
    return result;
}