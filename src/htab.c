#include <stdint.h>
#include <stddef.h>
#include <malloc.h>
#include <alloca.h>
#include <string.h>
#include "htab.h"



static HT_item* HT_new_item (const int8_t* key, const int8_t* value)
{
    HT_item* item = NULL;
    item = malloc(sizeof(HT_item));
    if(item) {
        item->key = strdup(key);
        item->value = strdup(value);
    }
    return item;
}

HT_base* HT_create ()
{
    HT_base* ht = NULL;
    ht = malloc(sizeof(HT_base));
    if(ht) {
        ht->size  = 52;
        ht->count = 0;
        ht->items = calloc(ht->size, sizeof(HT_item*));
    }
    return ht;
}

static void HT_free_item (HT_item* item)
{
    free(item->key);
    free(item->value);
    free(item);
}

void HT_free (HT_base* ht) 
{
    if(!ht) return;

    HT_item* tmp = NULL;
    for(size_t i = 0; i < ht->size; i++){
        tmp = ht->items[i];
        if(tmp) {
            HT_free_item(tmp);
        }
    }
    free(ht->items);
    free(ht);
}

static size_t ht_hash(const int8_t* s, const size_t a, const size_t m) {
    size_t hash = 0;
    const size_t len_s = strlen(s);
    for (size_t i = 0; i < len_s; i++) {
        hash += pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return hash;
}