#ifndef __LIST_H
#define __LIST_H
#include <stddef.h>
#include <stdbool.h>

typedef struct linked_list_item
{   
    struct linked_list_item* next;
    void*   data;
} LL_item;

typedef struct linked_list_base {
    LL_item* first;                 /* ptr to first list item */
    LL_item* last;                  /* ptr to last list item */
    size_t len;                     /* list length */
    size_t ds;                      /* data size */
} LL_base;
/**
 * @brief 
 * 
 * @param data_size 
 * @return LL_base 
 */
extern LL_base* LL_list_init (size_t data_size);
extern size_t LL_list_len(const LL_base* list);
extern bool LL_list_free (LL_base* to_free);
extern bool LL_pushf (LL_base *list_base, void const *data);
extern bool LL_pushb (LL_base *list_base, void const *data);
extern bool LL_popf (LL_base *list_base, void *data);
extern bool LL_popb (LL_base *list_base, void *data);

/*

extern bool LL_get_data(LL_item* const item, void const *data);
extern bool LL_set_data(LL_item* const item, void const *data);
extern LL_item LL_get_item(LL_base *list_base, size_t item_n);
extern bool LL_rem_item(LL_base list_base, LL_item* item);
extern bool LL_add_item(LL_base list_base, LL_item* item);
*/
#endif