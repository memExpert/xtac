#ifndef __LIST_H
#define __LIST_H
#include <stddef.h>
#include <stdbool.h>

typedef struct list
{
    void*  data;
    size_t data_sz;
    struct list*   next;
} LIST;


extern LIST* LIST_init(void* data, size_t data_sz);
extern bool LIST_addf(LIST **first, void const *data, size_t data_sz);
extern bool LIST_addl(LIST **const first, void const *data, size_t data_sz);

typedef struct linked_list_item
{
    struct linked_list_item* next;
    void*   data;
} LL_item;

typedef struct linked_list_base {
    LL_item* first;
    size_t list_len;
    size_t data_size;
} LL_base;

extern LL_base LL_list_init (size_t data_size);
extern bool LL_list_free (LL_base* to_free);
extern bool LL_pushf (LL_base *list_base, void const *data);
extern bool LL_popf (LL_base *list_base, void *data);
/*
extern bool LL_pushb(LL_base list_base, void const *data, size_t data_size);
extern bool LL_popb(LL_base const list_base, void *data, size_t data_size);
extern bool LL_get_data(LL_item* const item, void const *data);
extern bool LL_set_data(LL_item* const item, void const *data, size_t data_size);
extern bool LL_rem_item(LL_base list_base, LL_item* item);
extern bool LL_add_item(LL_base list_base, LL_item* item);
*/
#endif