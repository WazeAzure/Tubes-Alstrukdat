#include <stdio.h>
#include "../boolean.h"
#include "adjmatrix.h"

void CreateEmpty (AdjMatrix * M)
/* I.S. sembarang */
/* F.S. Sebuah M kosong terbentuk dengan tiap elemen */
{
    for(int i = 0; i < NMAX; i++){
        for(int j = 0; j < NMAX; j++){
            ElmtAdjMatrix(*M,i,j) = 0;
        }
    }
}

void setSymmetricElmt(AdjMatrix *M, int row, int col, boolean b){
    ElmtAdjMatrix(*M,row,col) = b;
    ElmtAdjMatrix(*M,col,row) = b;
}   

void setDiagonal(AdjMatrix *M, boolean b){
    for(int i = 0; i < NMAX; i++){
        ElmtAdjMatrix(*M,i,i) = b;
    }
}

void PrintAdjMatrix(AdjMatrix M)
/* I.S. terdefinisi */
/* F.S. Mencetak isi matriks adjacency  */
{
   int i=0, j=0;
	for(i=0;i<NMAX;i++){
		for(j=0;j<NMAX-1;j++){
			printf("%d ",  ElmtAdjMatrix(M, i, j));
		}
		printf("%d\n", ElmtAdjMatrix(M, i, NMAX-1));
	}
}