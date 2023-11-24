#include <stdio.h>
#include <stdlib.h>

#include "../Kicauan/kicauan.h"

#include "../Datetime/time.c"
#include "../Datetime/datetime.c"


#define CAPACITY 100

typedef struct
{
    KICAUAN* list;
    int size;
    int capacity;
} MAXHEAP ;

#define GETKICAU_HEAP(h,i) (h).list[i]
#define SIZE_HEAP(h) (h).size
#define CAPACITY_HEAP(h) (h).capacity
#define LIST_HEAP(h) (h).list

// Membuat heap kosong
void createHeap(MAXHEAP *h, int capacity);

// Mengecek apakah heap kosong
boolean isHeapEmpty(MAXHEAP h);

// Mengecek apakah heap penuh
boolean isHeapFull(MAXHEAP h);

// Menyuusun ulang max heap setelah dimasukkan elemen baru
void reorganizeHeap(MAXHEAP *h, int idx);


void insertHeap(MAXHEAP *h, KICAUAN k);

void displayHeap(MAXHEAP *h);

void updateHEAP(MAXHEAP *h, KICAUAN updatedKicau);





