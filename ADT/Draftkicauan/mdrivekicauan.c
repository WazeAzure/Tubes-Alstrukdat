#include <stdio.h>
#include "../../util.h"

int main() {
    Stack S;
    Word mawar;
    Word maw;
    ListUser l;
    KICAUAN k;
    Word hai;
    Word tes;
    createListUser(&l);
    addUser(&l,mawar,maw);
    CreateKicauan(&k,1,mawar,hai,tes);
    kicau(mawar);
    DraftKicauanCreateEmpty(&S);
    if(ADDR_TOP(S)==NULL){
        printf("DraftKicauan kosong berhasil dibuat\n");
    }
    buatDraft();
    lihatDraft(S);
    terbitDraft(&S);

    return 0;
}

// gcc -o draftkicau ADT/Draftkicauan/draftkicauan.c ADT/User/user.c ADT/Wordmachine/charmachine.c ADT/Wordmachine/wordmachine.c ADT/Kicauan/kicauan.c ADT/Draftkicauan/mdrivekicauan.c globalVar.c main.c ADT/pcolor/pcolor.c