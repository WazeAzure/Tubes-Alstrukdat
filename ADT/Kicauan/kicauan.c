#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

// #include "../Datetime/datetime.h"


// #include "../User/user.h"

#include "kicauan.h"
#include "../../globalVar.h"



#define endl printf("\n")

void CreateListKicauan(LISTKICAUAN* l, int CAPACITY){
    KICAUAN_CAPACITY(*l) = CAPACITY;
        KICAUAN_NEFF(*l) = 0;
    KICAUAN_BUFFER(*l) = (KICAUAN*)malloc(sizeof(KICAUAN) * CAPACITY);
    // printf("size - %lld\n", sizeof(KICAUAN_BUFFER(*l)));
}

void dealocateListKicauan(LISTKICAUAN *l){
    KICAUAN_NEFF(*l) = 0;
    KICAUAN_CAPACITY(*l) = 0;
    free(KICAUAN_BUFFER(*l));
}

void ExpandListKicauan(LISTKICAUAN* l){
    int add = 100 + l->CAPACITY;

    LISTKICAUAN l2;
    CreateListKicauan(&l2, add);
    l2.NEFF = l->NEFF;

    for(int i=0; i<l2.NEFF; i++){
        l2.buffer[i] = l->buffer[i];
    }
    dealocateListKicauan(l);
    *l = l2;
}

KICAUAN* newKicau(Word teks, Word Author, Word tagar){
    KICAUAN* new = (KICAUAN*)malloc(sizeof(KICAUAN));
    if(new != NULL){
        CreateKicauan(new, CurrentUserId, Author, teks, tagar);
        return new;
    } else {
        printf("Alokasi Kicauan di HEAP Memomry gagal. Mohon lakuakn KICAU kembali.\n");
        return NULL;
    }
}

void CreateKicauan(KICAUAN* kicauan, int idAuthor, Word Author, Word teks, Word tagar){
    kicauan->id = CounterKicauan;
    CounterKicauan++;

    kicauan->like = 0;
    kicauan->inc_balasan = 0;
    kicauan->Author = Author;
    kicauan->idAuthor = CurrentUserId;
    kicauan->teks = teks;
    kicauan->tagar = tagar;
    kicauan->daftar_utas = NULL;
    kicauan->daftar_balasan = NULL;

    long long int current_time = getCurrentTime();
    kicauan->timeCreated = (DetikToDATETIME(current_time));
}

void addKicauanLast(Word teks, Word Author, Word tagar){
    KICAUAN* new = newKicau(teks, Author, tagar);

    if(new == NULL) return ;

    ListKicauan.buffer[ListKicauan.NEFF] = *new;
    ListKicauan.NEFF++;

    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:");
    showKicauanContent(*new);
}

void showKicauanContent(KICAUAN kicauan){
    printf("| ID: %d\n", kicauan.id+1);
    printf("| idAuthor: %d\n", kicauan.idAuthor);
    printf("| %s\n", kicauan.Author.TabWord);
    printf("| "); TulisDATETIME(kicauan.timeCreated); printf("\n");
    printf("| %s\n", kicauan.teks.TabWord);
    if(kicauan.tagar.Length != 0){
        printf("| #%s\n", kicauan.tagar.TabWord);
    }
    printf("| Disukai: %d\n", kicauan.like);
    printf("| count balasan\t: %d\n", kicauan.inc_balasan);

    if(kicauan.daftar_balasan == NULL){
        printf("daftar balasan kosong\n");
    }
    if(kicauan.daftar_utas == NULL){
        printf("daftar utas kosong\n");
    }
}

int getIdAuthorFromIdKicau(int idKicau){
   return KICAU_IDAUTHOR(KICAUAN_ELMT(ListKicauan, idKicau));
}

boolean isFriend(int idKicau){
    int idAuthor = getIdAuthorFromIdKicau(idKicau);
    return (DaftarPertemanan.Tabword[idAuthor][CurrentUserId]);
}

boolean kicau(Word Author){
    printf("Masukkan kicauan:\n");
    Word teks;
    readWord(&teks, ';');

    if(teks.Length == 0){
        printf("Kicauan tidak boleh hanya berisi spasi/kosong!\n");
        return 0;
    }

    printf("Masukkan tagar:\n");
    Word tagar;
    readWord(&tagar, ';');

    if(ListKicauan.NEFF == ListKicauan.CAPACITY){
        ExpandListKicauan(&ListKicauan);
    }
    
    addKicauanLast(teks, Author, tagar);
    return 1;
}

void kicauan(){
    if(ListKicauan.NEFF == 0){
        printf("List Kicauan kosong.\n");
    }
    int i=0;
    for(i=0; i<ListKicauan.NEFF; i++){
        if(KICAUAN_ELMT(ListKicauan, i).idAuthor == CurrentUserId || isFriend(i) || !PRIVACY(USER(user, getIdAuthorFromIdKicau(i)))){
            showKicauanContent(ListKicauan.buffer[i]);
            endl;
        }
    }
}

void sukaKicauan(Word input){
    if(input.Length == 0){
        printf("Argumen tidak ditemukan\n");
        return ;
    }

    if(KICAUAN_NEFF(ListKicauan) == 0){
        printf("List Kicauan KOSONG!\n");
        return ;
    }
    
    int idKicau = WordToInt(input)-1;
    // printf("called hereasd ad as \n");
    if(idKicau >= KICAUAN_NEFF(ListKicauan) || idKicau < 0){
        printf("Tidak ditemukan kicauan dengan ID = %d;\n", idKicau);
        return ;
    }

    if(PRIVACY(USER(user, getIdAuthorFromIdKicau(idKicau))) && !isFriend(idKicau)){
        // true jika private dan blom diikuti
        printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        return ;
    }

    LIKE(KICAUAN_ELMT(ListKicauan, idKicau))++;
    printf("Selamat! kicauan telah disukai!\nDetil kicauan:");
    showKicauanContent(KICAUAN_ELMT(ListKicauan, idKicau));
}

void ubahKicauan(Word input){
    if(input.Length == 0){
        printf("Argumen tidak ditemukan\n");
        return ;
    }

    if(KICAUAN_NEFF(ListKicauan) == 0){
        printf("List Kicauan KOSONG!\n");
        return ;
    }

    int idKicau = WordToInt(input)-1;
    // printf("called hereasd ad as \n");
    if(idKicau >= KICAUAN_NEFF(ListKicauan) || idKicau < 0){
        printf("Tidak ditemukan kicauan dengan ID = %d;\n", idKicau);
        return ;
    }

    if(getIdAuthorFromIdKicau(idKicau) != CurrentUserId){
        // true jika private dan blom diikuti
        printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicau);
        return ;
    }

    Word teks;
    printf("Masukkan kicauan baru:\n");
    readWord(&teks, ';');
    
    KICAU_TEKS(KICAUAN_ELMT(ListKicauan, idKicau)) = teks;

    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:");
    showKicauanContent(KICAUAN_ELMT(ListKicauan, idKicau));
}

void showAllListKicauan(){
    if(ListKicauan.NEFF == 0){
        printf("List Kicauan kosong.\n");
    }
    int i=0;
    for(i=0; i<ListKicauan.NEFF; i++){
        showKicauanContent(ListKicauan.buffer[i]);
        endl;
    }
}