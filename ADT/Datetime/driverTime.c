#include <stdio.h>
#include "time.h"

int main()
{
    printf("------- DRIVER ADT DATETIME -------\n");
    TIME d,d1,d2;

    printf("Masukkan TIME yang diinginkan dengan format HH MM SS\n");
    BacaTIME(&d);
    printf("Datetime yang dimasukkan:\n");
    TulisTIME(d);

    printf("1 Detik setelah TIME yang dimasukkan: \n");
    printf("%d\n", NextDetik(d));

    printf("10 Detik setelah TIME yang dimasukkan: \n");
    printf("%d\n", NextNDetik(d,10));

    printf("1 Detik sebelum TIME yang dimasukkan: \n");
    printf("%d\n", PrevDetik(d));
    

    printf("10 Detik sebelum TIME yang dimasukkan: \n");
    printf("%d\n", PrevNDetik(d,10));

    printf("Mengubah TIME menjadi detik\n");
    printf("%ld\n", TIMEToDetik(d));

    printf("Masukkan detik untuk diubah menjadi TIME\n");
    int detik;
    scanf("%ld", &detik);
    TulisDATETIME(DetikToTIME(detik));


    printf("Pengecekkan antar dua TIME\n");
    printf("Masukkan T1: \n");
    BacaDATETIME(&d1);
    printf("Masukkan T2: \n");
    BacaDATETIME(&d2);

    printf("Pengecekkan apabila DATETIME sama, 0 jika tidak sama, 1 jika sama\n");
    printf("Hasil: %d, %d\n", TEQ(d1,d2));

    printf("Pengecekkan apabila DATETIME tidak sama, 0 jika sama, 1 jika tidak sama\n");
    printf("Hasil: %d %d\n", TNEQ(d1,d2));

    printf("Pengecekkan apabila D1 > D2, 0 jika salah, 1 jika benar\n");
    if (TNEQ(d1,d2))
    {
        printf("%d\n", TGT(d1,d2));
    } else
    {
        printf("Kedua DATETIME sama\n");
    }

    printf("Pengecekkan apabila D1 < D2, 0 jika salah, 1 jika benar\n");
    if (TNEQ(d1,d2))
    {
        printf("%d\n", TLT(d1,d2));
    } else
    {
        printf("Kedua DATETIME sama\n");
    }

    printf("Durasi antar dua TIME:\n");
    long int durasi;
    if (TGT(d1,d2))
    {

        durasi = Durasi(d1,d2);
    } else
    {
        durasi = Durasi(d2,d1);
    }
    printf("%ld\n", durasi);

}