/* File : prioqueuechar.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen prio */

#ifndef daftarpertemanan_H
#define daftarpertemanan_H

#include "../boolean.h"

// Ukuran Maksimum Row dan Eff dari AdjMatrix
#define NMAX 20

typedef boolean Eltype;

typedef struct 
{
    Eltype Tabword[NMAX][NMAX];
} DAFTARPERTEMANAN;

#define ElmtDaftarPertemanan(m,x,y) (m).Tabword[x][y]

void CreateEmptyDaftarPertemanan(DAFTARPERTEMANAN * M);
/* I.S. sembarang */
/* F.S. Sebuah M kosong terbentuk dengan tiap elemen */

void setSymmetricElmt(DAFTARPERTEMANAN *M, int row, int col, boolean b);
/* Mengubah elemen m(row,col) dan m(col,row) pada Adj Matriks M menjadi b */

void PrintDaftarPertemanan(DAFTARPERTEMANAN M);
/* I.S. terdefinisi */
/* F.S. Mencetak isi matriks adjacency  */

#endif
