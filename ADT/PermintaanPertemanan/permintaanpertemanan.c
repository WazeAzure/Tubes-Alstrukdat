#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "permintaanpertemanan.h"


/* ********* Prototype ********* */
boolean IsEmptyPermintaanPertemanan (PERMINTAANPERTEMANAN Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return(HeadPermintaanPertemanan(Q) == Nil && TailPermintaanPertemanan(Q) == Nil);
}

boolean IsFullPermintaanPertemanan (PERMINTAANPERTEMANAN Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return(NBElmtPermintaanPertemanan(Q) == MaxElPermintaanPertemanan(Q));
}

int NBElmtPermintaanPertemanan (PERMINTAANPERTEMANAN Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if(IsEmptyPermintaanPertemanan(Q)){
        return 0;
    } else{
        return((MaxElPermintaanPertemanan(Q) - HeadPermintaanPertemanan(Q) + TailPermintaanPertemanan(Q)) % MaxElPermintaanPertemanan(Q)) + 1;
    }
}

/* *** Kreator *** */
void MakeEmptyPermintaanPertemanan(PERMINTAANPERTEMANAN * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    infotype* T = malloc(sizeof(infotype) * (Max+1));
    if(T != NULL){
        (*Q).T = T;
        MaxElPermintaanPertemanan(*Q) = Max + 1;
    } else{
        MaxElPermintaanPertemanan(*Q) = 0;
    }
    HeadPermintaanPertemanan(*Q) = Nil;
    TailPermintaanPertemanan(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasiPermintaanPertemanan(PERMINTAANPERTEMANAN * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free((*Q).T);
    MaxElPermintaanPertemanan(*Q) = 0;
    HeadPermintaanPertemanan(*Q) = Nil;
    TailPermintaanPertemanan(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void EnqueuePermintaanPertemanan(PERMINTAANPERTEMANAN * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{   
    if(IsEmptyPermintaanPertemanan(*Q)){
        HeadPermintaanPertemanan(*Q) = 0;
        TailPermintaanPertemanan(*Q) = 0;
        InfoHeadPermintaanPertemanan(*Q) = X;
        InfoTailPermintaanPertemanan(*Q) = X;
    } else{
        int idx = HeadPermintaanPertemanan(*Q);
        while(JumlahTemanPermintaanPertemanan(ElmtPermintaanPertemanan(*Q,idx)) >= JumlahTemanPermintaanPertemanan(X) && idx != (TailPermintaanPertemanan(*Q)+1) % MaxElPermintaanPertemanan(*Q)){
            idx = (idx + 1) % MaxElPermintaanPertemanan(*Q);
        }
        int i = TailPermintaanPertemanan(*Q);
        while(i != (MaxElPermintaanPertemanan(*Q) + idx - 1) % MaxElPermintaanPertemanan(*Q)){
            ElmtPermintaanPertemanan(*Q,i+1) = ElmtPermintaanPertemanan(*Q,i);
            i = (MaxElPermintaanPertemanan(*Q) + i - 1) % MaxElPermintaanPertemanan(*Q);
        }
        ElmtPermintaanPertemanan(*Q,idx) = X;
        TailPermintaanPertemanan(*Q) = (TailPermintaanPertemanan(*Q) + 1) % MaxElPermintaanPertemanan(*Q);
    }
}

void DequeuePermintaanPertemanan (PERMINTAANPERTEMANAN * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if(HeadPermintaanPertemanan(*Q) == TailPermintaanPertemanan(*Q)){
        *X = InfoHeadPermintaanPertemanan(*Q);
        HeadPermintaanPertemanan(*Q) = Nil;
        TailPermintaanPertemanan(*Q) = Nil;
    } else{
        *X = InfoHeadPermintaanPertemanan(*Q);
        HeadPermintaanPertemanan(*Q) = (HeadPermintaanPertemanan(*Q) + 1) % MaxElPermintaanPertemanan(*Q);
    }
}

/* Operasi Tambahan */
void PrintPermintaanPertemanan (PERMINTAANPERTEMANAN Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    if(!IsEmptyPermintaanPertemanan(Q)){
        int i = HeadPermintaanPertemanan(Q);
        printf("[%d %s,",JumlahTemanPermintaanPertemanan(InfoHeadPermintaanPertemanan(Q)),NamaPermintaanPertemanan(InfoHeadPermintaanPertemanan(Q)));
        while(i != TailPermintaanPertemanan(Q)){
            if((i+1) % MaxElPermintaanPertemanan(Q) == TailPermintaanPertemanan(Q)){
                printf("%d %s",JumlahTemanPermintaanPertemanan(ElmtPermintaanPertemanan(Q,i+1)),NamaPermintaanPertemanan(ElmtPermintaanPertemanan(Q,i+1)));
            } else{
                printf("%d %s,",JumlahTemanPermintaanPertemanan(ElmtPermintaanPertemanan(Q,i+1)),NamaPermintaanPertemanan(ElmtPermintaanPertemanan(Q,i+1)));
            }
            i = (i+1) % MaxElPermintaanPertemanan(Q);
        }
        printf("]\n");
    } else{
        printf("[]\n");
    }
}