#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

#include "../Datetime/datetime.h"
#include "../Datetime/time.c"
#include "../Datetime/datetime.c"

#include "../User/user.h"

#include "kicauan.h"
#include "../../globalVar.h"

#define endl printf("\n")

void CreateListKicauan(LISTKICAUAN* l, int CAPACITY){
    l->CAPACITY = CAPACITY;
    l->NEFF = 0;
    l->buffer = (KICAUAN*)malloc(sizeof(KICAUAN) * l->CAPACITY);
    printf("size - %ld\n", sizeof(l->buffer));
}

void dealocateListKicauan(LISTKICAUAN *l){
    l->NEFF = 0;
    l->CAPACITY = 0;
    free(l->buffer);
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

KICAUAN* newKicau(Word teks, Word Author){
    KICAUAN* new = (KICAUAN*)malloc(sizeof(KICAUAN));
    if(new != NULL){
        CreateKicauan(new, 1, Author, teks);
        return new;
    } else {
        printf("Alokasi Kicauan di HEAP Memomry gagal. Mohon lakuakn KICAU kembali.\n");
        return NULL;
    }
}

void CreateDaftarBalasan(KICAUAN* kicauan){
    kicauan->daftar_balasan = NULL;
}

void CreateKicauan(KICAUAN* kicauan, int idAuthor, Word Author, Word teks){
    kicauan->id = CounterKicauan;
    CounterKicauan++;

    kicauan->like = 0;
    kicauan->inc_balasan = 0;
    kicauan->Author = Author;
    kicauan->idAuthor = CurrentUserId;
    kicauan->teks = teks;
    CreateDaftarBalasan(kicauan);
    kicauan->daftar_utas = NULL;
    long long int current_time = getCurrentTime();
    (*kicauan).timeCreated = DetikToDATETIME(current_time);
}

void addKicauanLast(Word teks, Word Author){
    KICAUAN* new = newKicau(teks, Author);

    ListKicauan.buffer[ListKicauan.NEFF] = *new;
    ListKicauan.NEFF++;
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

int getIdAuthorFromIdKicau(int idKicau){
   return KICAU_IDAUTHOR(KICAUAN_ELMT(ListKicauan, idKicau));
}

boolean isFriend(int idKicau){
    int idAuthor = getIdAuthorFromIdKicau(idKicau);
    return (DaftarPertemanan.Tabword[idAuthor][CurrentUserId]);
}

boolean isKicauanValid(Word teks){
    int i=0;
    while(teks.TabWord[i]){
        if(teks.TabWord[i] != ' '){
            return true;
        }
        i++;
    }
    return false;
}

void kicau(Word Author){
    printf("Masukkan kicauan:\n");
    Word teks;
    readWord(&teks, ';');

    if(!isKicauanValid(teks) && teks.Length != 0){
        printf("Kicaun tidak boleh hannya berisi spasi\n");
        return;
    }

    if(teks.Length == 0){
        printf("Kicauan tidak boleh hanya kosong!\n");
        return;
    }

    printf("Masukkan tagar:\n");
    Word tagar;
    readWord(&tagar, ';');

    addKicauanLast(teks, Author, tagar);
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
    
    int idKicau = WordToInt(input);
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

    int idKicau = WordToInt(input);
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
    }
}