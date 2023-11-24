#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
    printf("------- DRIVER ADT LIST LINIER-------\n");
    List l1,l2,l3;
    CreateList(&l1);
    CreateList(&l2);

    printf("Masukkan banyaknya elemen list yang diinginkan:\n");
    int n;
    scanf("%d",&n);

    printf("Masukkan isi dari list sesuai dengan banyaknya elemen yang dinginkan");
    for (int i=0; i<n;i++)
    {
        ElType x;
        scanf("%d", &x);
        insertLast(&l1,x);
        insertFirst(&l2,x);
    }

    printf("Hasil dari insert first (L2):\n");
    displayList(l2);
    printf("Hasil dari insert last (L1):\n");
    displayList(l1);

    printf("Panjang L1: %d\n", length(l1));
    printf("Panjang L2: %d\n", length(l2));

    printf("Menghapus element pertama L1....\n");
    ElType val;
    deleteFirst(&l1,&val);
    printf("Elemen yang dihapus: %d\n", val);
    displayList(l1);

    printf("Menghapus element terakhir L2....\n");
    ElType val2;
    deleteLast(&l2,&val2);
    printf("Elemen yang dihapus: &d\n", val);
    displayList(l2);

    printf("Menggabungkan 2 L1 dan L2....\n");
    l3 = concat(l1,l2);
    displayList(l3);

    printf("Membentuk List baru...\n");
    List l4;
    for (int i=0;i<5;i++)
    {
        insertLast(&l4,i);
    }
    displayList(l4);

    printf("Menambahkan elemen '100' baru pada index ke 2\n");
    insertAt(&l4,100,2);
    displayList(l4);

    printf("Menghapus elemen pada index ke 1\n");
    ElType temp;
    deleteAt(&l4,1,&temp);
    displayList(l4);
    printf("Elemen yang dihapus:\n", temp);

}