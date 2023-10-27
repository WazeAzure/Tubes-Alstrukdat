#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define endl printf("\n")

void createMatrix(int nRows,  int nCols, Matrix *m){
	ROW_EFF(*m) = nRows;
	COL_EFF(*m) = nCols;

	IdxType i, j;
	for(i=0;i<nRows;i++){
		for(j=0;j<nCols;j++){
			ELMT(*m, i, j) = 0;
		}
	}
}

boolean isMatrixIdxValid(int i, int j){
	return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}

IdxType getLastIdxRow(Matrix m){
	return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m){
	return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
	return (i >= 0 && i <= getLastIdxRow(m)) && (j >= 0 && j <= getLastIdxCol(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
	return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut){
	createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);

	IdxType i=0, j=0;
	for(i=0; i<ROW_EFF(mIn); i++){
		for(j=0; j<COL_EFF(mIn); j++){
			ELMT(*mOut, i, j) = ELMT(mIn, i, j);
		}
	}
}

void readMatrix(Matrix *m, int nRow, int nCol){
	createMatrix(nRow, nCol, m);

	IdxType i=0, j=0;
	for(i=0; i<nRow; i++){
		for(j=0; j<nCol; j++){
			ElType temp;
			scanf("%d", &temp);
			ELMT(*m, i, j) = temp;
		}
	}
}

void displayMatrix(Matrix m){
	IdxType i=0, j=0;
	for(i=0;i<ROW_EFF(m);i++){
		for(j=0;j<COL_EFF(m)-1;j++){
			printf("%d ", ELMT(m, i, j));
		}
		printf("%d\n", ELMT(m, i, COL_EFF(m)-1));
	}
}

Matrix addMatrix(Matrix m1, Matrix m2){
	Matrix m3;
	createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

	IdxType i, j;
	for(i=0;i<ROW_EFF(m1);i++){
		for(j=0;j<COL_EFF(m1);j++){
			ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
		}
	}
	return m3;
}

// section-10
Matrix subtractMatrix(Matrix m1, Matrix m2){
	Matrix m3;
	createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

	IdxType i, j;
	for(i=0;i<ROW_EFF(m1);i++){
		for(j=0;j<COL_EFF(m1);j++){
			ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
		}
	}
	return m3;
}
// section 11

Matrix multiplyMatrix(Matrix m1, Matrix m2){
	Matrix m3;
	createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);

	IdxType i;
	for(i=0;i<ROW_EFF(m1);i++){
		IdxType j;
		for(j=0;j<COL_EFF(m1);j++){
			IdxType k;
			int temp = 0;
			for(k=0;k<ROW_EFF(m2);k++){
				temp += (ELMT(m1, i, k) * ELMT(m2, k, j));
			}
			ELMT(m3, i, j) = temp;
		}
	}
	return m3;
}
// section-12

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod){
	Matrix m3;
	createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);

	IdxType i;
	for(i=0;i<ROW_EFF(m1);i++){
		IdxType j;
		for(j=0;j<COL_EFF(m1);j++){
			IdxType k;
			int temp = 0;
			for(k=0;k<ROW_EFF(m2);k++){
				temp += (ELMT(m1, i, k) * ELMT(m2, k, j)) % mod;
			}
			ELMT(m3, i, j) = temp % mod;
		}
	}
	return m3;
}
// section-13

Matrix multiplyByConst(Matrix m, ElType x){
	Matrix m3;
	createMatrix(ROW_EFF(m), COL_EFF(m), &m3);

	IdxType i, j;
	for(i=0;i<ROW_EFF(m);i++){
		for(j=0;j<COL_EFF(m);j++){
			ELMT(m3, i, j) = (ELMT(m, i, j) * x);
		}
	}
	return m3;
}
// section-14

void pMultiplyByConst(Matrix *m, ElType k){
	IdxType i, j;
	for(i=0;i<ROW_EFF(*m);i++){
		for(j=0;j<COL_EFF(*m);j++){
			ELMT(*m, i, j) = ELMT(*m, i, j) * k;
		}
	}
}
// section-15

boolean isMatrixEqual(Matrix m1, Matrix m2){
	if(COL_EFF(m1) == COL_EFF(m2) && ROW_EFF(m1) == ROW_EFF(m2) && getLastIdxCol(m1) == getLastIdxCol(m2) && countElmt(m1) == countElmt(m2)){
		IdxType i, j;
		for(i=0;i<ROW_EFF(m1);i++){
			for(j=0;j<COL_EFF(m1);j++){
				if(ELMT(m1, i, j) != ELMT(m2, i, j)){
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
// section-16

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
	return !isMatrixEqual(m1, m2);
}
// section-17

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
	return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m){
	return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m){
	return COL_EFF(m) == ROW_EFF(m);
}

boolean isSymmetric(Matrix m){
	if(isSquare(m)){
		IdxType i, j;
		for(i=0;i<ROW_EFF(m);i++){
			for(j=0;j<COL_EFF(m);j++){
				if(ELMT(m, i, j) != ELMT(m, j, i)){
					//printf("%d %d\n", i, j);
					//printf("%d %d\n", ELMT(m, i, j), ELMT(m, j, i));
					//printf("called1\n");
					return false;
				}
			}
		}
		return true;
	}
	//printf("called\n");
	return false;
}
// section-20

boolean isIdentity(Matrix m){
	if(isSquare(m)){
		// cek diagonal
		IdxType i, j;
		for(i=0;i<ROW_EFF(m);i++){
			if(ELMT(m, i, i) != 1) return false;
		}

		// cek kanan atas
		for(i=0; i<ROW_EFF(m)-1; i++){
			for(j=i+1;j<COL_EFF(m);j++){
				if(ELMT(m, i, j) != 0) return false;
			}
		}

		// cek kiri bawah
		for(i=1;i<ROW_EFF(m);i++){
			for(j=0;j<i;j++){
				if(ELMT(m, i, j) != 0) return false;
			}
		}
		return true;
	}
	return false;
}

boolean isSparse(Matrix m){
	IdxType i, j;
	float num = 0, zero = 0;

	for(i=0; i<ROW_EFF(m); i++){
		for(j=0;j<COL_EFF(m);j++){
			if(ELMT(m, i, j) != 0) num++;
			else zero++;
		}
	}
	
	float result = num*100 / (num+zero);
	if(result <= 5) return true;
	return false;
}

Matrix negation(Matrix m){
	return multiplyByConst(m, -1);
}

void pNegation(Matrix *m){
	pMultiplyByConst(m, -1);
}

float determinant(Matrix m){
	if(ROW_EFF(m) == 2){
		return (ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 0, 1) * ELMT(m, 1, 0));
	}
	
	float temp = 0;
	IdxType x;
	for(x=0; x<COL_EFF(m); x++){
		Matrix m2;
		createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &m2);
		IdxType r=0, c=0;
		IdxType i, j;
		for(i=0;i<ROW_EFF(m);i++){
			for(j=0;j<COL_EFF(m);j++){
				if(i == 0 || j == x){
					continue;
				} else {
					ELMT(m2, r, c) = ELMT(m, i, j);
					c++;
					if(c == COL_EFF(m2)){
						c = 0;
						r++;
					}
				}
			}
		}
		float det = (ELMT(m, 0, x) * determinant(m2));
		if(x%2 == 1) det *= -1;
		temp += det;
	}
	return temp;
}

Matrix transpose(Matrix m){
	Matrix m3;
	createMatrix(COL_EFF(m), ROW_EFF(m), &m3);

	IdxType i, j;
	for(i=0;i<ROW_EFF(m);i++){
		for(j=0;j<COL_EFF(m);j++){
			ELMT(m3, i, j) = ELMT(m, j, i);
		}
	}
	return m3;
}

void pTranspose(Matrix *m){
	IdxType i, j;
	for(i=0;i<ROW_EFF(*m);i++){
		for(j=i+1;j<COL_EFF(*m);j++){
			ElType temp = ELMT(*m, i, j);
			ELMT(*m, i, j) = ELMT(*m, j, i);
			ELMT(*m, j, i) = temp;
		}
	}
}
