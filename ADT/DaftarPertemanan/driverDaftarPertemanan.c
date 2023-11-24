#include <stdio.h>
#include <stdio.h>
#include "../boolean.h"
#include "daftarpertemanan.c"

int main()
{
    DAFTARPERTEMANAN D;
    printf("-------DRIVER DAFTAR PERTEMANAN-------\n");

    printf("Membuat Daftar Pertemanana Kosong");
    CreateEmptyDaftarPertemanan(&D);
    setSymmetricElmt(&D,1,1,1);
    setSymmetricElmt(&D,2,2,1);
    setSymmetricElmt(&D,1,5,1);
    setSymmetricElmt(&D,10,3,1);
    setSymmetricElmt(&D,10,2,1);

    PrintDaftarPertemanan(D);
    printf("Daftar Pertemanan Kosong");

    
}