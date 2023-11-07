#ifndef stackt_H
#define stackt_H

#include "../boolean.h"

#include "../Datetime/time.h"
#include "../Datetime/datetime.h"

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

#include "../Kicauan/kicauan.h"

#include "../User/user.h"

typedef struct draftKicau {
  DATETIME timeCreated;
  Word isiDraftKicauan;
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
#define isiDraft(d) (d).isiDraftKicauan
#define timeDraft(d) (d).timeCreated
#define NEXT_S(p) (p)->next
#define INFO_S(p) (p)->info
#define INFO_TIME(p) (p)->info.timeCreated
#define INFO_ISI(p) (p)->info.isiDraftKicauan
#define ADDR_TOP(s) (s).addrTop
#define TOP(s) (s).addrTop->info

/* ************ Prototype ************ */
AddressDraftKicau newNodeDraftKicau(DraftKicau x);
/* MengembalikanalamatsebuahNode hasilalokasidenganinfo = x, atau NIL jikaalokasigagal*/

/* *** Konstruktor/Kreator *** */
void DraftKicauanCreateEmpty(Stack *S);

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean DraftKicauanIsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushDraftKicau(Stack * S, DraftKicau X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopDraftKicau(Stack * S, DraftKicau* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void buatDraft ();
void lihatDraft(Stack S);
void terbitDraft (Stack* S);
void ubahDraft ();

#endif