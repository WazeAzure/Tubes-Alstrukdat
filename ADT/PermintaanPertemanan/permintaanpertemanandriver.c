#include <stdio.h>
#include "permintaanpertemanan.h"

int main(){
    PERMINTAANPERTEMANAN Q;
    // int val;
    infotype x1,x2,x3,x4,x5,x6,x7;
    Word nama,nama2,nama3;
    char test[5] = "HELLO";
    nama.TabWord[0] = 'r';
    nama.TabWord[1] = 'i';
    nama.TabWord[2] = 'c';
    nama.TabWord[3] = 'i';
    nama.TabWord[4] = '\0';
    nama2.TabWord[0] = 'r';
    nama2.TabWord[1] = 'i';
    nama2.TabWord[2] = 'c';
    nama2.TabWord[3] = 'o';
    nama2.TabWord[4] = '\0';
    nama3.TabWord[0] = 'r';
    nama3.TabWord[1] = 'i';
    nama3.TabWord[2] = 'c';
    nama3.TabWord[3] = 'e';
    nama3.TabWord[4] = '\0';
    x1.nama = nama;
    x1.jumlahTeman = 1;
    x2.nama = nama2;
    x2.jumlahTeman = 7;
    x3.nama = nama3;
    x3.jumlahTeman = 8;
    x4.nama = nama3;
    x4.jumlahTeman = 3;
    x6.nama = nama2;
    x6.jumlahTeman = 8;

    // PrintPermintaanPertemanan(Q);
    EnqueuePermintaanPertemanan(&Q,x2);
    PrintPermintaanPertemanan(Q);
    EnqueuePermintaanPertemanan(&Q,x1);
    PrintPermintaanPertemanan(Q);
    EnqueuePermintaanPertemanan(&Q,x3);
    PrintPermintaanPertemanan(Q);
    EnqueuePermintaanPertemanan(&Q,x6);
    PrintPermintaanPertemanan(Q);
    EnqueuePermintaanPertemanan(&Q,x4);
    PrintPermintaanPertemanan(Q);
    DequeuePermintaanPertemanan(&Q,&x5);
    PrintPermintaanPertemanan(Q);
    DequeuePermintaanPertemanan(&Q,&x5);
    PrintPermintaanPertemanan(Q);
    DequeuePermintaanPertemanan(&Q,&x5);
    DequeuePermintaanPertemanan(&Q,&x5);
    DequeuePermintaanPertemanan(&Q,&x5);
    PrintPermintaanPertemanan(Q);
    DequeuePermintaanPertemanan(&Q,&x5);

}