#ifndef _XTAC_HASH_TABLE_H
#define _XTAC_HASH_TABLE_H


#ifdef __cplusplus
extern "C"
{
#endif

typedef struct hash_table_item{
    int8_t* key;
    int8_t* value;
} HT_item;

typedef struct hash_table_base{
    size_t size;
    size_t count;
    HT_item** items;
} HT_base;

HT_base* HT_create ();
void HT_free (HT_base* ht);


/* end of _XTAC_HASH_TABLE_H */
#ifdef __cplusplus
}
#endif
#endif
