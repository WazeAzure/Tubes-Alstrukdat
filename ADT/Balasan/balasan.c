#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

#include "../Datetime/datetime.h"
#include "../Datetime/time.c"
#include "../Datetime/datetime.c"

#include "../User/user.h"

#include "balasan.h"
#include "../../globalVar.h"

#define endl printf("\n")

void CreateListBalasan(LISTBALASAN* l, int CAPACITY){
    l->CAPACITY = CAPACITY;
    l->NEFF = 0;
    l->buffer = (BALASAN*)malloc(sizeof(BALASAN) * l->CAPACITY);
    printf("size - %ld\n", sizeof(l->buffer));
}

void dealocateListBalasan(LISTBALASAN *l){
    l->NEFF = 0;
    l->CAPACITY = 0;
    free(l->buffer);
}

void ExpandListBalasan(LISTBALASAN* l){
    int add = 100 + l->CAPACITY;

    LISTBALASAN l2;
    CreateListBalasan(&l2, add);
    l2.NEFF = l->NEFF;

    for(int i=0; i<l2.NEFF; i++){
        l2.buffer[i] = l->buffer[i];
    }
    dealocateListBalasan(l);
    *l = l2;
}

BALASAN* newBalasan(Word teks, Word Author){
    BALASAN* new = (BALASAN*)malloc(sizeof(BALASAN));
    if(new != NULL){
        createBalasan(new, 1, Author, teks);
        return new;
    } else {
        printf("Alokasi BALASAN di HEAP Memomry gagal. Mohon lakuakn Balasan kembali.\n");
        return NULL;
    }
}

// void CreateDaftarBalasan(BALASAN* BALASAN){
//     BALASAN->daftar_balasan = NULL;
// }

void CreateBalasan(BALASAN* BALASAN, int idParent, int idAuthor, Word Author, Word teks){
    BALASAN->id = CounterBalasan;
    CounterBalasan++;
    
    BALASAN->idParent = idParent;
    BALASAN->like = 0;
    BALASAN->inc_balasan = 0;
    BALASAN->Author = Author;
    BALASAN->idAuthor = CurrentUserId;
    BALASAN->teks = teks;
    CreateDaftarBalasan(BALASAN);
    BALASAN->daftar_utas = NULL;
}

void showBalasanContent(BALASAN BALASAN){
    printf("idParent\t\t\t\t: %d\n", BALASAN.idParent);
    printf("id\t\t\t\t: %d\n", BALASAN.id);
    printf("like\t\t\t: %d\n", BALASAN.like);
    printf("idAuthor\t\t: %d\n", BALASAN.idAuthor);
    printf("count balasan\t: %d\n", BALASAN.inc_balasan);
    printf("isi teks\t\t: %s\n", BALASAN.teks.TabWord);
    printf("Author\t\t\t: %s\n", BALASAN.Author.TabWord);
    printf("datetime\t\t: ");
    long long int current_time = getCurrentTime();

    TulisDATETIME(DetikToDATETIME(current_time));

    endl;

    if(BALASAN.daftar_balasan == NULL){
        printf("daftar balasan kosong\n");
    }
    if(BALASAN.daftar_utas == NULL){
        printf("daftar utas kosong\n");
    }
}

void Balasan(Word Author){
    printf("Masukkan BALASAN:\n");
    Word teks;
    readWord(&teks, ';');

    if(teks.Length == 0){
        printf("BALASAN tidak boleh hanya berisi spasi!");
        return;
    }

    addBALASANLast(teks, Author);
}

void showAllListBalasan(){
    if(ListBalasan.NEFF == 0){
        printf("List BALASAN kosong.\n");
    }
    int i=0;
    for(i=0; i<ListBalasan.NEFF; i++){
        showBALASANContent(ListBalasan.buffer[i]);
    }
}