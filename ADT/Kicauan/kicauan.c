#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Datetime/datetime.h"
#include "../Datetime/time.c"
#include "../Datetime/datetime.c"

#include "kicauan.h"
#include "../../globalVar.h"

#define endl printf("\n")

void CreateKicauan(KICAUAN* kicauan, int idAuthor, Word Author){
    kicauan->id = CounterKicauan;
    CounterKicauan++;

    kicauan->like = 0;
    kicauan->inc_balasan = 0;
    kicauan->Author = Author;
    kicauan->idAuthor = idAuthor;
    kicauan->daftar_balasan = NULL;
    kicauan->daftar_utas = NULL;


}

void showKicauanContent(KICAUAN kicauan){
    printf("id\t\t: %d\n", kicauan.id);
    printf("like\t\t: %d\n", kicauan.like);
    printf("idAuthor\t: %d\n", kicauan.idAuthor);
    printf("count balasan\t: %d\n", kicauan.inc_balasan);
    printf("isi teks\t: %s\n", kicauan.teks.TabWord);
    printf("Author\t\t: %s\n", kicauan.Author.TabWord);
    printf("datetime\t: ");
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