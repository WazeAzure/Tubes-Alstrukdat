#include <stdio.h>
#include <stdlib.h>
#include "../Draftkicauan/draftkicauan.h"

#include"../Datetime/datetime.h"

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"
#include "../User/user.h"
#include "util.c"

/* ************ Prototype ************ */
AddressDraftKicau newNode(DraftKicau val){
    AddressDraftKicau p = (AddressDraftKicau) malloc(sizeof(Node));
    if(p!=NULL){
        INFO_S(p)= val;
        NEXT_S(p)= NULL;
    }
    return p;
}
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
{
    ADDR_TOP(*S) = NULL;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (ADDR_TOP(S) == NULL);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, DraftKicau X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    AddressDraftKicau p = newNode(X);
    if (p != NULL)
    {
        NEXT_S(p) = ADDR_TOP(*S);
        ADDR_TOP(*S) = p;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, DraftKicau* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = TOP(*S);
    AddressDraftKicau p = ADDR_TOP(*S);
    ADDR_TOP(*S) = NEXT_S(ADDR_TOP(*S));
    NEXT_S(p) = NULL;
    free(p);
}

void buatDraft (Stack S)
{
    // membaca draft menggunakan mesin kata
    Word isi;
    readWord(&isi,';');

    // masukkan draft ke Stack
    DraftKicau x;
    isiDraft(x) = isi;
    Push(&S,x);

    // pilihan hapus, unggah, singgah
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    // membaca pilihan
    Word command;
    char comm[100];
    
    do
    {
        readWord(&command,';');
        WordToChar(command,&comm);
    } while (strCompare(comm,'HAPUS') != 0 && strCompare(comm,'SIMPAN') != 0 && strCompare(comm,'TERBIT'));
    
    if (strCompare(comm,'HAPUS') == 1)
    {
        DraftKicau val;
        Pop(&S,&val);
        printf("Draf telah berhasil dihapus!\n");
    } else if (strCompare(comm,'SIMPAN'))
    {
        // gak ngelakuin apa apa karena diawal udah di push
        printf("Draf telah berhasil disimpan\n");
    } else if (strCompare(comm,'TERBIT') == 1)
    {
        terbitDraft(S);
    }



}
void lihatDraft(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else
    {
        printf("Ini draf terakhir anda:\n");
    }

    Word command;
    char comm[100];
    
    do
    {
        readWord(&command,';');
        WordToChar(command,&comm);
    } while (strCompare(comm,'HAPUS') != 0 && strCompare(comm,'SIMPAN') != 0 && strCompare(comm,'TERBIT'));
    // blm selese


}
void terbitDraft (Stack S);
void ubahDraft (Stack S);