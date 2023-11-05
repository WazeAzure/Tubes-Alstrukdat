#include <stdio.h>
#include "permintaanpertemanan.h"

int main(){
    PERMINTAANPERTEMANAN Q;
    // int val;
    infotype x1,x2,x3,x4,x5,x6,x7;
    Word nama;
    nama.TabWord[0] =  'a';
    nama.TabWord[1] =  'b';
    nama.TabWord[2] =  'c';
    nama.TabWord[3] =  'd';
    nama.TabWord[4] =  '\0';
    NamaPermintaanPertemanan(x1) = nama;
    JumlahTemanPermintaanPertemanan(x1) = 1;
    NamaPermintaanPertemanan(x2) = nama;
    JumlahTemanPermintaanPertemanan(x2) = 2;
    NamaPermintaanPertemanan(x3) = nama;
    JumlahTemanPermintaanPertemanan(x3) = 3;
    NamaPermintaanPertemanan(x4) = nama;
    JumlahTemanPermintaanPertemanan(x4) = 4;
    NamaPermintaanPertemanan(x5) = nama;
    JumlahTemanPermintaanPertemanan(x5) = 5;
    NamaPermintaanPertemanan(x6) = nama;
    JumlahTemanPermintaanPertemanan(x6) = 5;
    NamaPermintaanPertemanan(x7) = nama;
    JumlahTemanPermintaanPertemanan(x7) = 100;
    infotype val;
    MakeEmptyPermintaanPertemanan(&Q,5);
    EnqueuePermintaanPertemanan(&Q,x1);
    EnqueuePermintaanPertemanan(&Q,x4);
    EnqueuePermintaanPertemanan(&Q,x3);
    EnqueuePermintaanPertemanan(&Q,x7);
    PrintPermintaanPertemanan(Q);
    DequeuePermintaanPertemanan(&Q,&val);
    PrintPermintaanPertemanan(Q);
}