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

/* SELEKTOR LISTIDUTAS */
#define IDX_UNDEF (-1)
#define LISTIDUTAS__ELMT(li,i) (li).buffer[i]
#define nEFF(li) (li).nEFF
#define LISTIDUTAS_CAPACITY(l) (l).CAPACITY
#define LISTIDUTAS_BUFFER(l) (l).buffer

/* SELEKTOR UTAS */
#define FIRSTDAFTARUTAS(li) (li)
#define NEXTDAFTARUTAS(li) (li)->next
#define TEKSUTAS(li) (li)->teks
#define TIMEUTAS(li) (li)->timeCreated
#define UTAS_ELMT(li, i) (li).buffer[i]

/*PROTOTYPE*/

void CreateListIdUtas(LISTIDUTAS* ListIdUtas, int CAPACITY);

void dealocateListIdUtas(LISTIDUTAS *ListIdUtas);

void ExpandListIdUtas(LISTIDUTAS* ListIdUtas);

AddressUtas newUtas(Word teks);

void CreateListElementUtas(ListElemenUtas *daftarUtas);

void CreateListIdUtas(LISTIDUTAS* li,int  CAPACITY);

boolean isEmptyListIdUtas(LISTIDUTAS li);

boolean isEmptyDaftarUtas(ListElemenUtas daftarUtas);

IdxType getLastIdx(LISTIDUTAS li);

int lengthDaftarIdUtas(LISTIDUTAS li);

int lengthDaftarUtas(ListElemenUtas daftarUtas);

boolean isUtas(int idkicau);

void insertFirstDaftarUtas(ListElemenUtas *daftarUtas, Word teks);

void deleteFirstDaftarUtas(ListElemenUtas *daftarutas);

void deleteAtUtas(ListElemenUtas *daftarUtas, int index);

void utas(int idKicau);

void sambung_utas(Word idUtas,Word index);

void hapus_utas(Word Index, Word idutas);

void cetak_utas(int id_utas);

void insertLastIdUtas(LISTIDUTAS *ListIdUtas, int val);
#endif