#include "listdin.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    printf("------- DRIVER ADT LIST DINAMIS-------\n");
    ListDin l,l1,l2;

    printf("Membuat list dinamis dengan kapasitas 100\n");
    CreateListDin(&l,100);
    printf("Is Empty : %d\n", isEmpty(l));

    printf("Proses pengisian list\n");
    printf("Masukkan nilai N (jumlah elemen), dilanjutkan dengan elemennya\n");
    readList(&l);
    printf("Is full: %d\n", isFull(l));
    printList(l);
    printf("\n");

    printf("Menambahkan list dengan dirinya sendiri\n");
    l1 = plusMinusList(l,l,true);
    printList(l1);
    printf("\n");

    printf("Mengcopy list ke list yang lain\n");
    copyList(l,&l2);
    printList(l2);
    printf("\n");

    printf("Total dari penjumlahan elemen dalam list adalah:\n");
    printf("%d\n", sumList(l));

    printf("Memasukan elemen baru (10) ke dalam list\n");
    insertLast(&l,10);
    printList(l);
    printf("\n");

    printf("Menghitung jumlah kemunculan angka 10 dalam list l\n");
    countVal(l,10);
    printList(l);
    printf("\n");
    printf("Count val %d\n",countVal(l,10));

    ElType temp;
    printf("Mengapus elemen paling belakang list\n");
    deleteLast(&l,&temp);
    printList(l);
    printf("\n");

    printf("Mengurutkan list secara ascending\n");
    sort(&l,true);
    printList(l);
    printf("\n");

    print("Mengurutkan list secara descending\n");
    sort(&l, false);
    printList(l);
    printf("\n");
}