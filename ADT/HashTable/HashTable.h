/* Definisi type boolean */
// https://github.com/jamesroutley/write-a-hash-table/tree/master/05-methods

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "../Kicauan/kicauan.h"

typedef struct htel_node* AddressHT;
typedef struct htel_node{
    KICAUAN info;
    AddressHT next;
} HTel;

typedef struct {
    char* key;
    AddressHT val; 
} HT_item;

typedef struct {
    int size;
    int count;
    HT_item** items;
} HT_Table;

void ht_insert(HT_Table* ht,  char* key, KICAUAN* value);

void cari_kicauan(Word tagar);

#endif