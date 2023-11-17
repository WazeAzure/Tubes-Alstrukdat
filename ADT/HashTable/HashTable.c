#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "HashTable.h"
#include "../../globalVar.h"

HT_item* ht_new_item(char* k, AddressHT v) {
    HT_item* i = malloc(sizeof(HT_item));
    i->key = k;
    i->val = v;
    return i;
}

void ht_new(HT_Table* ht) {
    (*ht).size = 53;
    
    ht->count = 0;
    // printf("%ld\n", sizeof(HT_item*));
    ht->items = calloc((size_t)ht->size, sizeof(HT_item*));
}

void ht_del_item(HT_item* i) {
    free(i->key);
    // free(i.value);
    free(i);
}

// void ht_del_hash_table(HT_Table* ht) {
//     for (int i = 0; i < ht->size; i++) {
//         HT_item* item = ht->items[i];
//         if (item != NULL) {
//             ht_del_item(item);
//         }
//     }
//     free(ht->items);
//     free(ht);
// }

int ht_hash( char* s,  int a,  int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long) pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

int ht_get_hash (char* s,  int num_buckets, int attempt) {
    const int hash_a = ht_hash(s, 151, num_buckets);
    const int hash_b = ht_hash(s, 157, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void ht_insert(HT_Table* ht,  char* key, KICAUAN* value) {
    
    int index = ht_get_hash(key, ht->size, 0);

    if(ht->items[index] == NULL){
        HT_item* p = (HT_item*)malloc(sizeof(HT_item));
        ht->items[index] = p;

        if(ht->items[index]->key == NULL) printf("null here\n");
        printf("%s\n", key);
        (*(*ht).items[index]).key = key;

        AddressHT new = (AddressHT)malloc(sizeof(HTel));
        new->info = *value;
        new->next = NULL;

        (*(*ht).items[index]).val = new;

    } else {
        printf("yey\n");

        AddressHT new = (AddressHT)malloc(sizeof(HTel));
        new->info = *value;
        new->next = NULL;

        AddressHT pp =  (*(*ht).items[index]).val;
        if(pp == NULL) printf("pp null\n");
        printf("temp\n");
        while(pp->next != NULL){
            printf("%s\n", pp->info.teks.TabWord);
            pp = (*pp).next;
        }

        pp->next = new;
    }
    // HT_item* cur_item = ht->items[index];
    // int i = 1;
    // while (cur_item != NULL) {
    //     index = ht_get_hash(item->key, ht->size, i);
    //     cur_item = ht->items[index];
    //     i++;
    // } 

    // ht->items[index] = item;
    // ht->count++;
}

HT_item* ht_search(HT_Table* ht, char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    printf("%d\n", index);
    HT_item* item = ht->items[index];
    printf("%s\n", item->key);
    // int i = 1;
    // while (item != NULL) {
    //     if (strcmp(item->key, key) == 0) {
    //         return item->value;
    //     }
    //     index = ht_get_hash(key, ht->size, i);
    //     item = ht->items[index];
    //     i++;
    // } 
    return item;
    // return NULL;
}

void cari_kicauan(Word tagar){
    printf("hasil tagar | %s\n", tagar.TabWord);
    HT_item* item = ht_search(&HashTable, tagar.TabWord);
    
    AddressHT p = item->val;
    int i=0;
    while(p != NULL){
        showKicauanContent(p->info);
        printf("\n");
        p = p->next;
        printf("urutan ke - %d\n", i);
        i++;
    }
}