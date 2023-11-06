#include <stdio.h>
#include <stdlib.h>

#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"

#ifndef _UTAS_H
#define _UTAS_H

typedef struct nodeUtas* AddressUtas;
typedef struct nodeUtas {
    Word author;
    Word teks;
    DATETIME time;
    AddressUtas next;
} UTAS;

typedef AddressUtas ListElemenUtas;

typedef int IdxType;
// typedef int IdUtas;

typedef struct{
    int* buffer;
    int nEFF;
    int CAPACITY;
} LISTIDUTAS;

#define IDX_UNDEF (-1)
#define ELMT(li,i) (li).buffer[i]
#define nEFF(li) (li).nEFF
#define FIRST(l) (l)
/*PROTOTYPE*/

AddressUtas newUtas();

void CreateListIdUtas(LISTIDUTAS* li,int  CAPACITY);


// void CreateItemUtas(ITEMUTAS* utas, int index,Word author, Word utasan, DATETIME time);

// void CetakUtas(UTAS daftaridutas, KICAUAN *kicauan);

// void showUtasContent(UTAS utas);

// boolean isUtasExist(UTAS utas, int idUtas);

// void ReadUtas(UTAS *utas);

// int getIdAuthor();

// void ReadUtas(UTAS *utas);

// boolean isIndexValid(UTAS *utasan, int index);

// void deleteAtItemUtas(UTAS *utasan, ITEMUTAS *itemutas, int idx);

// boolean isIdUtasExist(UTAS utas, int idUtas);

// // void SambungUtas(int index, UTAS *utas);

// void hapus_utas(); 

#endif