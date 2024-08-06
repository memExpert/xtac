#include "../includes/list.h"
#include <inttypes.h>
#include <malloc.h>
#include <string.h>
/*
Add LIST_pushback(), LIST_pushforw(), LIST_popback, LIST_popforw, LIST_get_data,
LIST_update_data, LIST_delitem
*/

/*
    Фактически можно реализовать это как функции высшего порядка.
    Например передавать pop-функциям в качестве аргумента указатель на функции, вроде
    getdouble(void* list_data, double* dst). Внутри будет просто явное преобразование
    из поля data структуры элемента списка к даблу и переведение запись в dst.
*/




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















LL_base LL_list_init (size_t data_size) {
    LL_base list;
    list.data_size = data_size;
    list.first = NULL;
    list.list_len = 0;
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

void LL_item_free(LL_item* list_item) {
    if(list_item){
        free(list_item->data);
        free(list_item);
    }
}


static bool LL_inc_len(LL_base* list) {
    bool result = false;
    if(list->list_len < SIZE_MAX){
        list->list_len++;
        result = true;
    }
    return result;
}

static bool LL_dec_len(LL_base* list) {
    bool result = false;
    if(list->list_len > 0) {
        list->list_len--;
        result = true;
    }
    return result;
}



bool LL_list_free (LL_base* list) {
    bool isFree = false;
    LL_item* tmp = list->first;
    if(list) {
        while (tmp)
        {
            list->first = list->first->next;
            LL_item_free(tmp);
            tmp = list->first;
        }
        list->data_size = 0;
        list->list_len = 0;
        isFree = true;
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
    
    new_first->data = malloc(list_base->data_size);
    if(!new_first->data) {
        LL_dec_len(list_base);
        free(new_first);
        return false;
    }

    memmove(new_first->data, data, list_base->data_size);
    new_first->next = list_base->first;
    list_base->first = new_first;
    
    return true;
}

bool LL_popf (LL_base* list_base, void *data) {
    LL_item* tmp = NULL;
    if(!(list_base && data))  return false;
    if(!LL_dec_len(list_base)) return false;
    tmp = list_base->first;
    if(tmp) {
        memmove(data, tmp->data, list_base->data_size);
        list_base->first = tmp->next;
        LL_item_free(tmp);
    } else {
        LL_inc_len(list_base);
        return false;
    }
    return true;
}

#define COUNT_OF(_x) (sizeof(_x) / sizeof(*_x))

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = 0;
    LL_base list = LL_list_init(sizeof(int));

    for(size_t i = 0; i < COUNT_OF(arr); i++){
        LL_pushf(&list, (void*)(arr + i));
        printf("%"PRId64"\n", list.list_len);
    }
    while(LL_popf(&list, (void*)&result)) {
        printf("%d ", result);
    }
    printf("\n");
    return 0;
}