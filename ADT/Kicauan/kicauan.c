#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

#include "../Datetime/datetime.h"
#include "../Datetime/time.c"
#include "../Datetime/datetime.c"

#include "kicauan.h"
#include "../../globalVar.h"

#define endl printf("\n")

AddressKicauan newKicau(Word teks, Word Author){
    AddressKicauan new = (AddressKicauan)malloc(sizeof(KICAUAN));
    if(new != NULL) CreateKicauan(new, 1, Author, teks);
    return new;
}

void CreateDaftarBalasan(KICAUAN* kicauan){
    kicauan->daftar_balasan = NULL;
}

void CreateKicauan(AddressKicauan kicauan, int idAuthor, Word Author, Word teks){
    kicauan->id = CounterKicauan;
    CounterKicauan++;

    kicauan->like = 0;
    kicauan->inc_balasan = 0;
    kicauan->Author = Author;
    kicauan->idAuthor = CurrentUserId;
    kicauan->teks = teks;
    CreateDaftarBalasan(kicauan);
    kicauan->daftar_utas = NULL;
    kicauan->next = NULL;
}

void addKicauan(Word teks, Word Author){
    AddressKicauan new = newKicau(teks, Author);

    AddressKicauan p = ListKicauan;
    
    if(p == NULL){
        ListKicauan = new;
    } else {
        while(p != NULL){
            p = p->next;
        }
        p = new;
    }
}

void showKicauanContent(KICAUAN kicauan){
    printf("id\t\t\t\t: %d\n", kicauan.id);
    printf("like\t\t\t: %d\n", kicauan.like);
    printf("idAuthor\t\t: %d\n", kicauan.idAuthor);
    printf("count balasan\t: %d\n", kicauan.inc_balasan);
    printf("isi teks\t\t: %s\n", kicauan.teks.TabWord);
    printf("Author\t\t\t: %s\n", kicauan.Author.TabWord);
    printf("datetime\t\t: ");
    long long int current_time = getCurrentTime();

    TulisDATETIME(DetikToDATETIME(current_time));

    endl;

    if(kicauan.daftar_balasan == NULL){
        printf("daftar balasan kosong\n");
    }
    if(kicauan.daftar_utas == NULL){
        printf("daftar utas kosong\n");
    }
}

void kicau(Word Author){
    printf("Masukkan kicauan:\n");
    Word teks;
    readWord(&teks, ';');

    if(teks.Length == 0){
        printf("Kicauan tidak boleh hanya berisi spasi!");
    }

    addKicauan(teks, Author);
}

void showAllListKicauan(){
    AddressKicauan p = ListKicauan;
    while(p != NULL){
        printf("calledn here\n");
        showKicauanContent(*p);
        p = p->next;
    }
}