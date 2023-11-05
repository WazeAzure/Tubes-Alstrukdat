#include <stdio.h>
#include "AdjMatrix.h"

int main(){
    AdjMatrix M;
    CreateEmpty(&M);
    setSymmetricElmt(&M,10,0,true);
    setDiagonal(&M,true);
    PrintAdjMatrix(M);
}