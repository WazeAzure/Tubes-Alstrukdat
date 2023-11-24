#include <stdio.h>
#include "../../util.h"

#include "../../globalVar.c"
#include "../Wordmachine/charmachine.c"
#include "../Wordmachine/wordmachine.c"
#include "../DisjoinSetUnion/circle.c"
#include "../../util.c"
#include "../pcolor/pcolor.c"
#include "../User/user.c"
#include "../Kicauan/kicauan.c"

int main() {

    Word nama;
    Word sandi;
    KICAUAN k;
    printf("Masukkan nama: \n");
    readWord(&nama, ';');
    printf("\n");

    // Handle kasus nama sudah terdaftar, loop sampai nama valid.
    while (!isNamaValid(nama) || nama.Length == 0){
        if (nama.Length == 0) {
            printf("Nama tidak boleh kosong, isi kembali!\n\n");
        } else {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n\n");
        }
        printf("Masukkan nama: \n");
        readWord(&nama, ';');
        printf("\n");
    }
    printf("\n");

    // Membaca kata sandi dengan mesin kata
    printf("Masukkan kata sandi: \n");
    readWord(&sandi, ';');
    printf("\n\n");

    // Add user
    user.CounterUser = 0;
    CurrentUserId = 0;
    addUser(&user,nama,sandi);
    Word tes, tagar;
    CreateKicauan(&k,1,nama,tes,tagar);
    kicau(tes);
    if(ADDR_TOP(DRAFT(USER(user, userId(nama))))==NULL){
        printf("DraftKicauan kosong berhasil dibuat\n");
    }
    buatDraft();
    lihatDraft(DRAFT(USER(user, userId(nama))));
    return 0;
}

// gcc -o draftkicau ADT/Draftkicauan/draftkicauan.c ADT/User/user.c ADT/Wordmachine/charmachine.c ADT/Wordmachine/wordmachine.c ADT/Kicauan/kicauan.c ADT/Draftkicauan/mdrivekicauan.c globalVar.c main.c ADT/pcolor/pcolor.c