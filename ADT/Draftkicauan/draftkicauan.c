#include <stdio.h>
#include <stdlib.h>
#include "../Draftkicauan/draftkicauan.h"

#include"../Datetime/datetime.h"
#include"../Datetime/datetime.c"
#include "../Datetime/time.h"

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"
#include "../User/user.h"
#include "util.c"

#include "../User/user.h"

#include "draftkicauan.h"

#include "globalVar.h"

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
void DraftKicauanCreateEmpty(Stack *S)
{
    ADDR_TOP(*S) = NULL;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean DraftKicauanIsEmpty(Stack S)
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

    // pilihan hapus, unggah, singgah
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    // membaca pilihan
    Word command;
    char comm[100];
    
    do
    {
        readWord(&command,';');
        WordToChar(command,&comm);
    } while (strCompare(comm,'HAPUS') != 0 && strCompare(comm,'SIMPAN') != 0 && strCompare(comm,'TERBIT') != 0);
    
    if (strCompare(comm,'HAPUS') == 1)
    {
        DraftKicau val;
        // gak ngelakuin apa apa karena diawal belum di push
        printf("Draf telah berhasil dihapus!\n");
    } else if (strCompare(comm,'SIMPAN') ==1)
    {

        int time_second = getCurrentTime();
        DATETIME timeDraftK = DetikToDATETIME(time_second);
        timeDraft(x) = timeDraftK;

        Push(&S,x);
        printf("Draf telah berhasil disimpan\n");
    } else if (strCompare(comm,'TERBIT') == 1)
    {
        terbitDraft(S);
    }



}
void lihatDraft(Stack S)
{
    if (DraftKicauanIsEmpty(S))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else
    {
        printf("Ini draf terakhir anda:\n");
        printf("| ");
        //print datetime
        printf("| ");

        DraftKicau draf = TOP(S);
        printWord(draf.isiDraftKicauan);
        prinf("\n");
        
    }

    Word command;
    char comm[100];
    
    do
    {
        readWord(&command,';');
        WordToChar(command,&comm);
    } while (strCompare(comm,'HAPUS') != 0 && strCompare(comm,'UBAH') != 0 && strCompare(comm,'TERBIT') != 0 && strCompare(comm,'KEMBALI'));

    if (strCompare(comm,'HAPUS') == 1)
    {
        DraftKicau val;
        // gak ngelakuin apa apa karena diawal belum di push
        Pop(&S,&val);
        printf("Draf telah berhasil dihapus!\n");
    } else if (strCompare(comm,'UBAH'))
    {
        ubahDraft(S);
    } else if (strCompare(comm,'TERBIT') == 1)
    {
        terbitDraft(S);
    } else if (strCompare(comm,'KEMBALI') == 1)
    {
        printf("Kembali ke menu.\n");
    }

}
void terbitDraft (Stack S)
{
    DraftKicau x;
    Pop(&S,&x);
    printf("Selamat! Draf kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    prinf("| ID = %d\n", CurrentUserId);
    printf("| ");
    printWord(USER_NAMA(USER(user, CurrentUserId)));
    printf("| ");
    // print datetime
    printf("| ");
    printWord(x.isiDraftKicauan);
    printf("\n");
    printf("| Disukai : 0\n");
    newKicau(x.isiDraftKicauan,USER_NAMA(USER(user, CurrentUserId)));

    
}
void ubahDraft (Stack S)
{
    // meminta input baru
    printf("Masukkan draf yang baru:\n");
    

    //menerima masukkan
    Word newIsi;
    readWord(&newIsi,';');


    //mengganti draft awal dengan draft baru
    DraftKicau val,new;
    Pop(&S,&val)

    isiDraft(new) = newIsi;


    // pilihan hapus, unggah, singgah
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    // membaca pilihan
    Word command;
    char comm[100];
    
    do
    {
        readWord(&command,';');
        WordToChar(command,&comm);
    } while (strCompare(comm,'HAPUS') != 0 && strCompare(comm,'SIMPAN') != 0 && strCompare(comm,'TERBIT') != 0);
    
    if (strCompare(comm,'HAPUS') == 1)
    {
        DraftKicau val;
        // gak ngelakuin apa apa karena diawal belum di push
        printf("Draf telah berhasil dihapus!\n");
    } else if (strCompare(comm,'SIMPAN') ==1)
    {

        int time_second = getCurrentTime();
        DATETIME timeDraftK = DetikToDATETIME(time_second);
        timeDraft(new) = timeDraftK;

        Push(&S,new);
        printf("Draf telah berhasil disimpan\n");
    } else if (strCompare(comm,'TERBIT') == 1)
    {
        terbitDraft(S);
    }

}