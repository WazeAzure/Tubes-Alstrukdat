#ifndef POHONTREE_H
#define POHONTREE_H

#include "boolean.h"

/* Selektor */
#define NODE(p) (p)->info
#define CHILD(p) (p)->child
#define SIBLING(p) (p)->sibling

typedef int ElType;
typedef struct treeNode* Address;

typedef struct treeNode {
    ElType info;
    Address child;     // pointer to the leftmost child
    Address sibling;   // pointer to the next sibling
} TreeNode;

/* Definisi PohonTree */
/* PohonTree kosong p = NULL */

typedef Address Tree;

Tree NewTree(ElType root, Tree firstChild);
/* Menghasilkan sebuah pohon tree dari root dan firstChild, jika alokasi berhasil
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree(ElType root, Tree firstChild, Tree *p);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon tree p dari root dan firstChild, jika alokasi
   berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.child=NULL, p↑.sibling=NULL
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode(Address p);
/* I.S. p terdefinisi
   F.S. p dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty(Tree p);
/* Mengirimkan true jika p adalah pohon tree yang kosong */

boolean isOneElmt(Tree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUner(Tree p);
/* Mengirimkan true jika pohon tree tidak kosong, p adalah pohon uner:
   hanya mempunyai satu anak (child tidak NULL) */

boolean isBinary(Tree p);
/* Mengirimkan true jika pohon tree tidak kosong, p adalah pohon tree: 
   memiliki lebih dari satu anak atau tidak memiliki anak sama sekali */

/* ****** Display Tree ***** */
void printTree(Tree p, int h);
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon tree: (A(B()C()D()E())F()G(H()I())) akan ditulis sbb:
A
  B
  C
  D
  E
F
G
  H
  I
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
#endif
