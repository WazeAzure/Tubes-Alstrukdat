#include <stdio.h>
#include "../boolean.h"
#include "daftarpertemanan.h"

void CreateEmptyDaftarPertemanan(DAFTARPERTEMANAN * M)
/* I.S. sembarang */
/* F.S. Sebuah M kosong terbentuk dengan tiap elemen */
{
    for(int i = 0; i < NMAX; i++){
        for(int j = 0; j < NMAX; j++){
            ElmtDaftarPertemanan(*M,i,j) = 0;
        }
    }
}

void setSymmetricElmt(DAFTARPERTEMANAN *M, int row, int col, boolean b){
    ElmtDaftarPertemanan(*M,row,col) = b;
    ElmtDaftarPertemanan(*M,col,row) = b;
}  

void PrintDaftarPertemanan(DAFTARPERTEMANAN M)
/* I.S. terdefinisi */
/* F.S. Mencetak isi matriks adjacency  */
{
   int i=0, j=0;
	for(i=0;i<NMAX;i++){
		for(j=0;j<NMAX-1;j++){
			printf("%d ",  ElmtDaftarPertemanan(M, i, j));
		}
		printf("%d\n", ElmtDaftarPertemanan(M, i, NMAX-1));
	}
}