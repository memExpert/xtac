#ifndef __LIST_H
#define __LIST_H
#include <stddef.h>
#include <stdbool.h>

typedef struct linked_list_item
{   
    struct linked_list_item* next;
    void* data;
} LL_item;

typedef struct linked_list_base {
    LL_item** first;                 /* [*]->[ ]->[ ]->[ ]->NULL     */
    LL_item** last;                  /* [ ]->[ ]->[ ]->[*]->NULL     */
    size_t    len;                   /* list length                  */
    size_t    data_sz;               /* sizeof(your_own_t/default_t) */
} LL_base;

typedef enum {
    LL_EXEC_SUCCESS = 1,
    LL_EXEC_NULL_BASE_PTR,
    LL_EXEC_NO_MEMORY,
    LL_EXEC_LIST_BLOCKED,
    LL_EXEC_LIST_FULL,
    LL_EXEC_LIST_EMPTY
} LL_EXEC_RESULT;

/*
extern LL_base* LL_list_init (size_t data_size);
extern size_t LL_list_len(const LL_base* list);
extern bool LL_list_free (LL_base* to_free);
extern bool LL_pushf (LL_base *list_base, void const *data);
extern bool LL_pushb (LL_base *list_base, void const *data);
extern bool LL_popf (LL_base *list_base, void *data);
extern bool LL_popb (LL_base *list_base, void *data);
*/
/*

extern bool LL_get_data(LL_item* const item, void const *data);
extern bool LL_set_data(LL_item* const item, void const *data);
extern LL_item LL_get_item(LL_base *list_base, size_t item_n);
extern bool LL_rem_item(LL_base list_base, LL_item* item);
extern bool LL_add_item(LL_base list_base, LL_item* item);
*/
#endif