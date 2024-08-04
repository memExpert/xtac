#include "../includes/list.h"
#include <inttypes.h>
#include <malloc.h>
#include <string.h>

static LIST* LIST_item_init(void) {
    LIST* new_list_item = (LIST*) malloc(sizeof(LIST));
    if(new_list_item) {
        new_list_item->data = NULL;
        new_list_item->next = NULL;
        new_list_item->data_sz = 0;
    }
    return new_list_item; 
}

bool LIST_item_set_data(LIST* const item, const void *data, size_t data_sz) {
    if(item && data){
        memmove(item->data, data, data_sz);
        item->data_sz = data_sz;
    }
    return item && data ? true : false;
}

static LIST* LIST_item_create(const void *data, size_t data_sz) {
    LIST *item = LIST_item_init();

    if (item){
        item->data = malloc(data_sz);
        if(item->data){
            LIST_item_set_data(item, data, data_sz);
        }
        item->next = NULL;
    }
    return item;
}

LIST* LIST_init(void* data, size_t data_sz) {
    return LIST_item_create(data, data_sz);
}

bool LIST_addf(LIST** first, const void *data, size_t data_sz) {
    LIST* new_first = NULL;
    if(!first || !(*first)) return false;
    new_first = LIST_item_create(data, data_sz);
    if(new_first) {
        new_first->next = *first;
        *first = new_first;
    }
    return new_first ? true : false;
}

bool LIST_addl(LIST** const first, const void *data, size_t data_sz) {
    LIST* current = *first;
    LIST* new_last = NULL;
    if(!first) return false;
    new_last = LIST_item_create(data, data_sz);
    if(new_last) {
        while(current->next){
            current = current->next;
        }
        current->next = new_last;
    }
    return new_last ? true : false;
}
