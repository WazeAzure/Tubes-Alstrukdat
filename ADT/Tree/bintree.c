#include "bintree.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
      BinTree new_tree = (BinTree) malloc (sizeof (TreeNode));
      if (new_tree != NULL) {
         ROOT(new_tree) = root;
         LEFT(new_tree) = left_tree;
         RIGHT(new_tree) = right_tree;
      }
      return new_tree;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
{
   *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
{
   Address new_node = (Address) malloc (sizeof (TreeNode));
   if (new_node != NULL) {
      ROOT(new_node) = val;
      LEFT(new_node) = NULL;
      RIGHT(new_node) = NULL;
   }
   return new_node;
}

void deallocTreeNode (Address p)
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
{
   free(p);
}

boolean isTreeEmpty (BinTree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
   return (p == NULL);
}
boolean isOneElmt (BinTree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
   return (!isTreeEmpty(p) && (LEFT(p) == NULL) && (RIGHT(p) == NULL));
}

boolean isUnerLeft (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
{
   return (!isTreeEmpty(p) && (LEFT(p) != NULL) && (RIGHT(p) == NULL));
}

boolean isUnerRight (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
{
   return (!isTreeEmpty(p) && (LEFT(p) == NULL) && (RIGHT(p) != NULL));
}
boolean isBinary (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
{
   return (!isTreeEmpty(p) && (LEFT(p) != NULL) && (RIGHT(p) != NULL));
}
/* ****** Display Tree ***** */
void printPreorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
   printf("(");
    if (!isTreeEmpty(p)){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}
void printInorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
   printf("(");
    if (!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}
void printPostorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
   printf("(");
    if (!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}
void BetterPrintTree(BinTree P, int h, int lv){
    if(!isTreeEmpty(P)){
        int i;
        for(i = 0; i < h*lv; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(P));
        BetterPrintTree(LEFT(P), h, lv+1);
        BetterPrintTree(RIGHT(P), h, lv+1);
    }
}
void printTree(BinTree P, int h){
    BetterPrintTree(P, h, 0);
}