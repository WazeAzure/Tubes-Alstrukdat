#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "prioqueue.h"


/* ********* Prototype ********* */
boolean IsEmpty (PrioQueue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return(Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return(NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if(IsEmpty(Q)){
        return 0;
    } else{
        return((MaxEl(Q) - Head(Q) + Tail(Q)) % MaxEl(Q)) + 1;
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    infotype* T = malloc(sizeof(infotype) * (Max+1));
    if(T != NULL){
        (*Q).T = T;
        MaxEl(*Q) = Max + 1;
    } else{
        MaxEl(*Q) = 0;
    }
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free((*Q).T);
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{   
    if(IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) = X;
        InfoTail(*Q) = X;
    } else{
        int idx = Head(*Q);
        while(Prio(Elmt(*Q,idx)) >= Prio(X) && idx != (Tail(*Q)+1) % MaxEl(*Q)){
            idx = (idx + 1) % MaxEl(*Q);
        }
        int i = Tail(*Q);
        while(i != (MaxEl(*Q) + idx - 1) % MaxEl(*Q)){
            Elmt(*Q,i+1) = Elmt(*Q,i);
            i = (MaxEl(*Q) + i - 1) % MaxEl(*Q);
        }
        Elmt(*Q,idx) = X;
        Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
    }
}

void Dequeue (PrioQueue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if(Head(*Q) == Tail(*Q)){
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else{
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    if(!IsEmpty(Q)){
        int i = Head(Q);
        printf("[%d %s,",Prio(InfoHead(Q)),Info(InfoHead(Q)));
        while(i != Tail(Q)){
            if((i+1) % MaxEl(Q) == Tail(Q)){
                printf("%d %s",Prio(Elmt(Q,i+1)),Info(Elmt(Q,i+1)));
            } else{
                printf("%d %s,",Prio(Elmt(Q,i+1)),Info(Elmt(Q,i+1)));
            }
            i = (i+1) % MaxEl(Q);
        }
        printf("]");
    } else{
        printf("[]");
    }
}