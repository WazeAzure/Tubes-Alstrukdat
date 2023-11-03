#include <stdio.h>
#include <stdlib.h>
#include "draftkicauan.h"

/* ************ Prototype ************ */
AddressDraftKicau newNode(DraftKicau val){
    AddressDraftKicau p = (AddressDraftKicau) malloc(sizeof(Node));
    if(p!=NULL){
        INFO_S(p)= val;
        NEXT_S(p)= NULL;
    }
    return p;
}
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
{
    ADDR_TOP(*S) = NULL;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (ADDR_TOP(S) == NULL);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, DraftKicau X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    AddressDraftKicau p = newNode(X);
    if (p != NULL)
    {
        NEXT_S(p) = ADDR_TOP(*S);
        ADDR_TOP(*S) = p;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, DraftKicau* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = TOP(*S);
    AddressDraftKicau p = ADDR_TOP(*S);
    ADDR_TOP(*S) = NEXT_S(ADDR_TOP(*S));
    NEXT_S(p) = NULL;
    free(p);
}

void buatDraft (Stack S);
void lihatDraft(Stack S);
void terbitDraft (Stack S);
void ubahDraft (Stack S);