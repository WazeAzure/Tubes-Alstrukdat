/* File : prioqueuechar.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen prio */

#ifndef adjmatrix_H
#define adjmatrix_H

#include "../boolean.h"

// Ukuran Maksimum Row dan Eff dari AdjMatrix
#define NMAX 20

typedef boolean Eltype;

typedef struct 
{
    Eltype Tabword[NMAX][NMAX];
} AdjMatrix;

#define ElmtAdjMatrix(m,x,y) (m).Tabword[x][y]

void CreateEmpty(AdjMatrix * M);
/* I.S. sembarang */
/* F.S. Sebuah M kosong terbentuk dengan tiap elemen */

void setSymmetricElmt(AdjMatrix *M, int row, int col, boolean b);
/* Mengubah elemen m(row,col) dan m(col,row) pada Adj Matriks M menjadi b */

void setDiagonal(AdjMatrix *M, boolean b);
/* Mengubah elemen m(i,i) pada Adj Matriks M menjadi true */

void PrintAdjMatrix(AdjMatrix M);
/* I.S. terdefinisi */
/* F.S. Mencetak isi matriks adjacency  */

#endif
