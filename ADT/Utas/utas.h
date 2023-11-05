#include <stdio.h>
#include <stdlib.h>
#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"

#include "../../globalVar.h"

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
// typedef int IdUtas;

typedef struct{
    int* buffer;
    int NEFF;
    int CAPACITY;
} LISTIDUTAS;


#define FIRST_UTAS(linkedlist) (linkedlist)
#define IDX_UNDEF (-1)


#define INDEX_ITEMUTAS(u) (u).index
#define INPUT_ITEMUTAS(u) (u).utasan
#define TIME_ITEMUTAS(u) (u).time
#define AUTHOR_ITEMUTAS(u) (u).author

#define INFO_UTAS(p) (p)->info
#define NEXT_UTAS(p) (p)->next


/*PROTOTYPE*/
void CreateListIdUtas(LISTIDUTAS* l,int  CAPACITY);
/*Membentuk suat*/

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