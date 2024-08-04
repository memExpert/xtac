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

#endif