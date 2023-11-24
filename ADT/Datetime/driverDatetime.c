#include <stdio.h>
#include "../../util.c"
#include "../../globalVar.c"
#include "../Wordmachine/wordmachine.c"
#include "../Wordmachine/charmachine.c"
#include "../pcolor/pcolor.c"
#include "../User/user.c"
#include "../DisjoinSetUnion/circle.c"
#include "../Kicauan/kicauan.c"



int main()
{
    printf("------- DRIVER ADT DATETIME -------\n");
    DATETIME d,d1,d2;

    printf("Masukkan DATETIME yang diinginkan dengan format DD MM YYYY hh mm ss\n");
    BacaDATETIME(&d);
    printf("Datetime yang dimasukkan:\n");
    TulisDATETIME(d);

    printf("Tanggal maksimum pada tanggal yang dimasukkan:\n");
    printf("%d\n", GetMaxDay(Month(d),Year(d)));

    printf("10 Detik setelah DATETIME yang dimasukkan: \n");
    printf("%d\n", DATETIMENextNDetik(d,10));

    printf("10 Detik sebelum DATETIME yang dimasukkan: \n");
    printf("%d\n", DATETIMEPrevNDetik(d,10));

    printf("Mengubah DATETIME menjadi detik\n");
    printf("%lld\n", DATETIMEToDetik(d));

    printf("Masukkan detik untuk diubah menjadi DATETIME\n");
    int detik;
    scanf("%lld\n", &detik);
    TulisDATETIME(DetikToDATETIME(detik));


    printf("Pengecekkan antar dua Datetime\n");
    printf("Masukkan D1: \n");
    BacaDATETIME(&d1);
    printf("Masukkan D2: \n");
    BacaDATETIME(&d2);

    printf("Pengecekkan apabila DATETIME sama, 0 jika tidak sama, 1 jika sama\n");
    printf("Hasil: %d, %d\n", DEQ(d1,d2));

    printf("Pengecekkan apabila DATETIME tidak sama, 0 jika sama, 1 jika tidak sama\n");
    printf("Hasil: %d %d\n", DNEQ(d1,d2));

    printf("Pengecekkan apabila D1 > D2, 0 jika salah, 1 jika benar\n");
    if (DNEQ(d1,d2))
    {
        printf("%d\n", DGT(d1,d2));
    } else
    {
        printf("Kedua DATETIME sama\n");
    }

    printf("Pengecekkan apabila D1 < D2, 0 jika salah, 1 jika benar\n");
    if (DNEQ(d1,d2))
    {
        printf("%d\n", DLT(d1,d2));
    } else
    {
        printf("Kedua DATETIME sama\n");
    }

    printf("Durasi antar dua DATETIME:\n");
    long int durasi;
    if (DGT(d1,d2))
    {

        durasi = DATETIMEDurasi(d1,d2);
    } else
    {
        durasi = DATETIMEDurasi(d2,d1);
    }
    printf("%ld\n", durasi); 
    
}