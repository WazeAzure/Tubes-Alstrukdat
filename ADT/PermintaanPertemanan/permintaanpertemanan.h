/* File : prioqueuechar.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen prio */

#ifndef permintaanpertemanan_H
#define permintaanpertemanan_H

#include "../boolean.h"
#include "../Wordmachine/wordmachine.h"

/* Definisi elemen dan address */
typedef struct {
    int jumlahTeman;  /* jumlah teman yang dimiliki dengan yang terbesar memiliki prioritas tertinggi */
    Word nama;  /* elemen karakter */
} infotype;
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct node *Address;
typedef struct node{
    infotype value;
    Address next;
}Node;

typedef struct {
    Address first;   /* tabel penyimpan elemen */
    int jumlah_permintaan;
} PERMINTAANPERTEMANAN;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueChar, maka akses elemen : */
#define FirstPermintaanPertemanan(Q)         (Q).first
#define JumlahPermintaanPertemanan(Q)         (Q).jumlah_permintaan
#define ValuePermintaanPertemanan(P)         (P)->value
#define NextPermintaanPertemanan(P)         (P)->next
#define JumlahTemanPermintaanPertemanan(P)  (P)->value.jumlahTeman
#define NamaPermintaanPertemanan(P)         (P)->value.nama

/* ********* Prototype ********* */
boolean IsEmptyPermintaanPertemanan(PERMINTAANPERTEMANAN Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */

/* *** Kreator *** */
void CreateEmptyPermintaanPertemanan(PERMINTAANPERTEMANAN * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong dengan definisi di atas: */

/****************** Manajemen Memori ******************/
Address AlokasiPermintaanPertemanan(infotype val);
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka ValuePermintaanPertemanan(P)=val, NextPermintaanPertemanan(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

/* *** Destruktor *** */
void DeAlokasiPermintaanPertemanan(Address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/* *** Primitif Add/Delete *** */
void EnqueuePermintaanPertemanan(PERMINTAANPERTEMANAN * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void DequeuePermintaanPertemanan(PERMINTAANPERTEMANAN * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPermintaanPertemanan(PERMINTAANPERTEMANAN Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

#endif
