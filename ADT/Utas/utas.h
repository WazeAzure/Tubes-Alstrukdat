#include <stdio.h>
#include "../Wordmachine/wordmachine.h"
#include "../Datetime/datetime.h"
#include "../Linkedlist/listlinier.h"

#include "../../globalVar.h"

#ifndef _UTAS_H
#define _UTAS_H

typedef struct {
    Word author;
    Word utasan;
    DATETIME time;
} ITEMUTAS;
// typedef int IdUtas;
typedef struct nodeutas *AddressUtas;
typedef struct nodeutas{
    ITEMUTAS* info; 
    Address next;
} UTAS ;

typedef AddressUtas UTAS;

#define FIRST_UTAS(linkedlist) (linkedlist)
#define IDX_UNDEF (-1)


#define INDEX_ITEMUTAS(u) (u).index
#define INPUT_ITEMUTAS(u) (u).utasan
#define TIME_ITEMUTAS(u) (u).time
#define AUTHOR_ITEMUTAS(u) (u).author

#define INFO_UTAS(p) (p)->info
#define NEXT_UTAS(p) (p)->next


/*PROTOTYPE*/
void CreateUtas(UTAS* daftaridutas,int  CounterUtas);
/*Membentuk suat*/

void CreateItemUtas(ITEMUTAS* utas, int index,Word author, Word utasan, DATETIME time);

void CetakUtas(UTAS daftaridutas, KICAUAN *kicauan);

void showUtasContent(UTAS utas);

boolean isUtasExist(UTAS utas, int idUtas);

void ReadUtas(UTAS *utas);

int getIdAuthor();

void ReadUtas(UTAS *utas);

boolean isIndexValid(UTAS *utasan, int index);

void deleteAtItemUtas(UTAS *utasan, ITEMUTAS *itemutas, int idx);

boolean isIdUtasExist(UTAS utas, int idUtas);

// void SambungUtas(int index, UTAS *utas);

void hapus_utas(); 

#endif