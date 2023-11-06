#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "permintaanpertemanan.h"


/* ********* Prototype ********* */
boolean IsEmptyPermintaanPertemanan (PERMINTAANPERTEMANAN Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return(FirstPermintaanPertemanan(Q) == NULL);
}

/* *** Kreator *** */
void CreateEmptyPermintaanPertemanan(PERMINTAANPERTEMANAN * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    FirstPermintaanPertemanan(*Q) = NULL;
    JumlahPermintaanPertemanan(*Q) = 0;
}

Address AlokasiPermintaanPertemanan(infotype val)
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka ValuePermintaanPertemanan(P)=val, NextPermintaanPertemanan(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    Address P = (Address) malloc(sizeof(Node));
    if(P != NULL){
        ValuePermintaanPertemanan(P) = val;
        NextPermintaanPertemanan(P) = NULL;
    }
    return P;
}

/* *** Destruktor *** */
void DeAlokasiPermintaanPertemanan(Address P)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free(P);
}

/* *** Primitif Add/Delete *** */
void EnqueuePermintaanPertemanan(PERMINTAANPERTEMANAN * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{   
    Address P = AlokasiPermintaanPertemanan(X);
    if(P != NULL){
        if(IsEmptyPermintaanPertemanan(*Q)){
            FirstPermintaanPertemanan(*Q) = P;
        } else{
            Address before = NULL;
            Address inspos = FirstPermintaanPertemanan(*Q);
            while(JumlahTemanPermintaanPertemanan(inspos) >= X.jumlahTeman && NextPermintaanPertemanan(inspos) != NULL){
                before = inspos;
                inspos = NextPermintaanPertemanan(inspos);
            }
            if(before == NULL){
                if(JumlahTemanPermintaanPertemanan(P) > JumlahTemanPermintaanPertemanan(inspos)){
                    FirstPermintaanPertemanan(*Q) = P;
                    NextPermintaanPertemanan(P) = inspos; 
                } else{
                    NextPermintaanPertemanan(P) = NextPermintaanPertemanan(inspos);
                    NextPermintaanPertemanan(inspos) = P;
                }
            } else{
                NextPermintaanPertemanan(before) = P;
                NextPermintaanPertemanan(P) = inspos;
            }
        }
    }
    JumlahPermintaanPertemanan(*Q)++;
}

void DequeuePermintaanPertemanan (PERMINTAANPERTEMANAN * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{   
    if(IsEmptyPermintaanPertemanan(*Q)){
        printf("Daftar teman sudah kosong");
    } else{
        Address P = FirstPermintaanPertemanan(*Q);
        *X = ValuePermintaanPertemanan(P);
        FirstPermintaanPertemanan(*Q) = NextPermintaanPertemanan(P);
        DeAlokasiPermintaanPertemanan(P);
        JumlahPermintaanPertemanan(*Q)--;
    }
}

/* Operasi Tambahan */
void PrintPermintaanPertemanan (PERMINTAANPERTEMANAN Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
[ < nama1 jumlah_teman1 >, < nama2 jumlah_teman2 >, ...]
*/
{
    if(IsEmptyPermintaanPertemanan(Q)){
        printf("[]\n");
    } else{
        printf("[");
        Address P = FirstPermintaanPertemanan(Q);
        while(NextPermintaanPertemanan(P) != NULL){
            printf("< %s %d >,", NamaPermintaanPertemanan(P).TabWord, JumlahTemanPermintaanPertemanan(P));
            P = NextPermintaanPertemanan(P);
        }
        printf("< %s %d >]\n",NamaPermintaanPertemanan(P).TabWord, JumlahTemanPermintaanPertemanan(P));
    }
}