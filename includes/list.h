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

/*
Появилась идея с разбиением списка на фреймы. Таким образом можно было бы сократить количество операций,
необходимых для нахождение элемента. Типа, должен создаваться подсписок из адресов элементов основного
списка. Хранится, например, каждый 100й элемент, и, если необходимо найти элемент, математически, исходя
из длинны основного списка, находить ближайший к нему элемент и от него искать.

Нужно получше разобраться с многопоточностью, чтобы запускать перераспределение фреймов (по факту просто
пускать указатель от первого элемента в поисках каждого сотого элемента), чтобы при сортировке не ломать фреймы.

Также можно поступить и с подсписками. Каждый из них при достижении длинны в 100 элементов будет
создавать внутри себя такой же подсписок и относительно него считаться главным. Все это будет работать рекурсивно.

Много элементов L1 списка -> увеличение количества элементов L2 списка -> увеличение количества элементов L3 списка.

Еще сильнее это ускорить получится сделав список двусвязным.
*/

#ifndef __LIST_H
#define __LIST_H
#include <stddef.h>
#include <stdbool.h>

typedef struct linked_list_item {   
    struct linked_list_item* next;
    void* data;
} LL_item;

typedef enum linked_list_state {
    LL_READY,   /* list is free for use                           */
    LL_NA,      /* list isn't exitst or something else went wrong */
    LL_WR,      /* some thread just writing this list             */
    LL_RD       /* some thread just reading this list             */
} LL_state;

typedef struct linked_list_base {
    LL_item** first;                 /* [*]->[ ]->[ ]->[ ]->NULL     */
    LL_item** last;                  /* [ ]->[ ]->[ ]->[*]->NULL     */
    size_t    len;                   /* list length                  */
    size_t    data_sz;               /* sizeof(your_own_t/default_t) */
    LL_state  state;                 /* current list state           */
} LL_base;

typedef enum {
    LL_EXEC_SUCCESS = 0,
    LL_EXEC_NULL_BASE_PTR,
    LL_EXEC_NO_MEMORY,
    LL_EXEC_LIST_BLOCKED,
    LL_EXEC_LIST_FULL,
    LL_EXEC_LIST_EMPTY,
    LL_EXEC_INDEX_OUT_OF_RANGE,
    LL_EXEC_NO_DATA_PTR
} LL_EXEC_RESULT;


extern size_t LL_length (const LL_base* list);
extern LL_base* LL_create_base (size_t data_size);
extern LL_state LL_get_state (const LL_base* list);
extern LL_EXEC_RESULT LL_pushf (LL_base* list, const void* data);
extern LL_EXEC_RESULT LL_pushb (LL_base* list, const void* data);
extern LL_EXEC_RESULT LL_popf (LL_base* list, void* data);
extern LL_EXEC_RESULT LL_popb (LL_base* list, void* data);
extern LL_EXEC_RESULT LL_getn (const LL_base* list, void* dst, size_t n);
extern LL_EXEC_RESULT LL_setn (LL_base* list, const void* data, size_t pos);
extern LL_EXEC_RESULT LL_insn (LL_base* list, const void* data, size_t pos);
extern LL_EXEC_RESULT LL_deln (LL_base* list, const void* data, size_t pos);

extern void LL_free (LL_base** list_base);
/*
TODO next functions:
extern void* LL_getval(LL_base* list, size_t pos);
extern LL_EXEC_RESULT LL_delete(LL_base* list, size_t pos);
extern LL_EXEC_RESULT LL_getdel(LL_base* list, void* data, size_t pos);
extern LL_EXEC_RESULT LL_insert(LL_base* list, void* data, size_t pos);
extern void LL_free_from(size_t pos);
extern void LL_free_to(size_t pos);
extern size_t LL_search(LL_base* list);
extern LL_EXEC_RESULT LL_sort(...);
extern void* LL_to_arr(...);
extern LL_base* LL_cp(LL_base* list);
*/


#endif