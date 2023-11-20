#include <stdio.h>
#include "daftarpertemanan.h"

int main(){
    DAFTARPERTEMANAN M;
    CreateEmptyDaftarPertemanan(&M);
    setSymmetricElmt(&M,10,0,true);
    PrintAdjMatrix(M);
}