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
    DATETIME timeCreated;
    AddressUtas next;
} NodeElemenUtas;

typedef AddressUtas ListElemenUtas;


typedef int IdxType;
// typedef int IdUtas;

// List dinamis yang menyimpan idUtas
typedef struct{
    int* buffer;
    int nEFF;
    int CAPACITY;
} LISTIDUTAS;

#define IDX_UNDEF (-1)
#define ELMT(li,i) (li).buffer[i]
#define nEFF(li) (li).nEFF

#define FIRSTDAFTARUTAS(li) (li)
#define NEXTDAFTARUTAS(li) (li)->next
#define TEKSUTAS(li) (li)->teks
#define TIMEUTAS(li) (li)->timeCreated

/*PROTOTYPE*/

AddressUtas newUtas();

AddressUtas newUtas(Word teks);

void CreateListElementUtas(ListElemenUtas *daftarUtas);

void utas(int idKicau);

void CreateListIdUtas(LISTIDUTAS* li,int  CAPACITY);

boolean isEmptyListIdUtas(LISTIDUTAS li);

boolean isEmptyDaftarUtas(ListElemenUtas daftarUtas);

IdxType getLastIdx(LISTIDUTAS li);

int lengthDaftarIdUtas(LISTIDUTAS li);

int lengthDaftarUtas(ListElemenUtas daftarUtas);

boolean isUtas(int idKicau);

void insertFirstDaftarUtas(ListElemenUtas *daftarUtas, Word teks);

void deleteFirstDaftarUtas(ListElemenUtas *daftarutas,Word *teks,int index);

void utas(int idKicau);

void sambung_utas(int index, ListElemenUtas *daftarUtas, int idKicau);

void hapus_utas(int index,LISTIDUTAS li, int idUtas, ListElemenUtas *daftarutas, Word *teks);

#endif