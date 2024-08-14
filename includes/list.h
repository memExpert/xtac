/**
 * @file list.h
 * @author Hanchar Maksim (hancharmaksimq@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-09
 * 
 * @copyright Copyright (c) 2024 Hanchar Maksim
 * 
 */

#ifndef _XTAC_LINKED_LIST_H
#define _XTAC_LINKED_LIST_H
#include <stddef.h>
#include <stdbool.h>

typedef struct linked_list_item {   
    struct linked_list_item* next;
    void* data;
} LL_item;

typedef enum linked_list_state {
    LL_READY,       /* list is free for use                           */
    LL_NA,          /* list isn't exitst or something else went wrong */
    LL_WR,          /* some thread just writing this list             */
    LL_RD           /* some thread just reading this list             */
} LL_state;

typedef struct linked_list_base {
    LL_item** first;                 /* [*]->[ ]->[ ]->[ ]->NULL     */
    LL_item** last;                  /* [ ]->[ ]->[ ]->[*]->NULL     */
    size_t    len;                   /* list length                  */
    size_t    data_sz;               /* sizeof(your_own_t/default_t) */
    LL_state  state;                 /* current list state           */
} LL_base;

typedef enum {
    LL_EXEC_SUCCESS = 0,             /* execution OK                */
    LL_EXEC_NULL_BASE_PTR,           /* LL_base == NULL             */
    LL_EXEC_NO_MEMORY,               /* can't allocate memory for new object  */
    LL_EXEC_LIST_BLOCKED,            /* some thread blocked list    */
    LL_EXEC_LIST_FULL,               /* list size == SIZE_MAX       */
    LL_EXEC_LIST_EMPTY,              /* list size == 0              */
    LL_EXEC_INDEX_OUT_OF_RANGE,      /* [get]n(list,n) if n > LL_length(list) */
    LL_EXEC_NO_DATA_PTR              /* if trying to push NULL      */
} LL_EXEC_RESULT;

/**
 * @brief return length of provided list (0 if provided NULL)
 * 
 * @param list list created by LL_create_base()
 * @return size_t 
 */
size_t LL_length (const LL_base* list);

/**
 * @brief creates list. Must be called if you want to use this API.
 * 
 * @param data_size sizeof structure that you want to store in list
 * @return LL_base* 
 */
LL_base* LL_create_base (size_t data_size);

/**
 * @brief return current list state. Use for multithreads.
 * 
 * @param list list created by LL_create_base()
 * @return LL_state 
 */
LL_state LL_get_state (const LL_base* list);

/**
 * @brief insert item into list from forward side. Data will be copied.
 * 
 * @param list list created by LL_create_base()
 * @param data pointer to data that must be put into list
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_pushf (LL_base* list, const void* data);

/**
 * @brief insert item into list from back side. Data will be copied.
 * 
 * @param list list created by LL_create_base()
 * @param data pointer to data that must be put into list
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_pushb (LL_base* list, const void* data);

/**
 * @brief copy data from first list element to provided pointer if provided, and
 * item will free.
 * 
 * @param list list created by LL_create_base()
 * @param data pointer to allocated memory or NULL
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_popf (LL_base* list, void* data);

/**
 * @brief copy data from last list element to provided pointer if provided, and
 * item will free.
 * 
 * @param list list created by LL_create_base()
 * @param data pointer to allocated memory or NULL
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_popb (LL_base* list, void* data);

/**
 * @brief copy data from provided list position to provided pointer. 
 * If pos > LL_length() return LL_EXEC_INDEX_OUT_OF_RANGE
 * 
 * @param list list created by LL_create_base()
 * @param dst pointer to allocated memory
 * @param pos position in list from where data will be copied
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_getn (const LL_base* list, void* dst, size_t pos);

/**
 * @brief set data from provided pointer to list item by provided position. 
 * If pos > LL_length() return LL_EXEC_INDEX_OUT_OF_RANGE
 * 
 * @param list list created by LL_create_base()
 * @param dst pointer to allocated memory
 * @param pos position in list where data will be copied
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_setn (LL_base* list, const void* data, size_t pos);

/**
 * @brief create new list item in provided position with provided data
 * 
 * @param list list created by LL_create_base()
 * @param dst pointer to allocated memory
 * @param pos position in list where data will be copied
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_insn (LL_base* list, const void* data, size_t pos);

/**
 * @brief delete an existing list item at the specified position and copy the
 * data from it to the specified data pointer
 * 
 * @param list list created by LL_create_base()
 * @param dst pointer to allocated memory or NULL
 * @param pos position in list where data will be copied
 * @return LL_EXEC_RESULT 
 */
LL_EXEC_RESULT LL_deln (LL_base* list, void* data, size_t pos);


LL_EXEC_RESULT LL_cpft (LL_base* list, void* data, size_t from, size_t to);


LL_EXEC_RESULT LL_delft(LL_base* list, void* data, size_t from, size_t to);


/**
 * @brief free all list and set provided pointer to NULL
 * 
 * @param list_base 
 */
void LL_free (LL_base** list_base);



/*
TODO next functions:

extern size_t LL_search(LL_base* list);
extern LL_EXEC_RESULT LL_sort(...);
extern void* LL_to_arr(...);
extern LL_base* LL_cp(LL_base* list);
*/


#endif