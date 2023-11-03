#ifndef stackt_H
#define stackt_H

#include "../boolean.h"

#include "../Datetime/datetime.h"
#include "../Datetime/time.c"
#include "../Datetime/datetime.c"

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef struct draftKicau {
  DATETIME timeCreated;
  Word isiDraft;
} DraftKicau;

typedef struct node* AddressDraftKicau;
typedef struct node
{
  DraftKicau info;
  AddressDraftKicau next;
} Node;


typedef struct { 
  AddressDraftKicau addrTop;  
} Stack;

/* ************ Selektor ************ */
#define isiDraft(d) (d).isiDraft;
#define timeDraft(d) (d).timeCreated;
#define NEXT_S(p) (p)->next;
#define INFO_S(p) (p)->info;
#define ADDR_TOP(s) (s).addrTop
#define TOP(s) (s).addrTop->info

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, DraftKicau X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, DraftKicau* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif