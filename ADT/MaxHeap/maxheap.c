#include <stdio.h>
#include <stdlib.h>
#include "maxheap.h"

// Membuat heap kosong
void createHeap(MAXHEAP *h, int capacity)
{
    LIST_HEAP(*h) = (KICAUAN*) malloc(capacity*sizeof(KICAUAN));
    SIZE_HEAP(*h) = 0;
    CAPACITY_HEAP(*h) = capacity;
    
}

boolean isHeapEmpty(MAXHEAP h)
{
    return (SIZE_HEAP(h) == 0);
}

boolean isHeapFull(MAXHEAP h)
{
    return (SIZE_HEAP(h) == CAPACITY);
}
// Menyuusun ulang max heap setelah dimasukkan elemen baru
void reorganizeHeap(MAXHEAP *h, int idx)
{
    int parent = (idx - 1) / 2;

    if ((LIKE(GETKICAU_HEAP(*h,parent))) < (LIKE(GETKICAU_HEAP(*h,idx))))
    {
        KICAUAN temp = GETKICAU_HEAP(*h, parent);
        GETKICAU_HEAP(*h, parent) = GETKICAU_HEAP(*h, idx);
        GETKICAU_HEAP(*h, idx) = temp;

        reorganize(h, parent);
    }
}


void insertHeap(MAXHEAP *h, KICAUAN k)
{
    if (!isFull(*h))
    {   
        LIST_HEAP(*h)[SIZE_HEAP(*h)] = k;
        reorganize(h, SIZE_HEAP(*h));
        SIZE_HEAP(*h)++;
    }
}


void displayHeap(MAXHEAP *h)
{
    int idx; 
    if (SIZE_HEAP(*h) < 8)
    {
        idx = SIZE_HEAP(*h);
    } else
    {
        idx = 8;
    }

    for (int i=0;i< idx;i++)
    {
        showKicauanContent(GETKICAU_HEAP(*h,i));
    }
}

boolean validIndexHeap(int idx, MAXHEAP *h)
{
    return ( idx < SIZE_HEAP(*h) || idx > 0);
}

void updateHEAP(MAXHEAP *h, KICAUAN updatedKicau)
{   
    // Inisialisasi untuk mencari index
    int idx = -1;
    int i = 0;
    // Nyari kicauan yang lama
    while (i < SIZE_HEAP(*h) && KICAU_ID(GETKICAU_HEAP(*h, i)) != KICAU_ID(updatedKicau))
    {
        i++;
    }
    if (i<SIZE_HEAP(*h))
    {
        idx = i;
    }
    if (idx != -1)
    {
        LIKE(GETKICAU_HEAP(*h,idx)) = LIKE(updatedKicau);
        reorganizeHeap(h,idx);

    } else
    {
        insertHeap(h,updatedKicau);
    }

}



