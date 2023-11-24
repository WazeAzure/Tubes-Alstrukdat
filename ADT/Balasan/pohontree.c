#include "pohontree.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../globalVar.h"
#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"


AddressTree newTreeNode(ElTypeTree* val) {
    AddressTree newNode = (AddressTree)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        NODE(newNode) = *val;
        CHILD(newNode) = NULL;
        SIBLING(newNode) = NULL;
    }
    return newNode;
}

void deallocTreeNode(AddressTree p) {
    free(p);
}

boolean isTreeEmpty(Tree p) {
    return (p == NULL);
}

boolean isOneElmt(Tree p) {
    return (p != NULL && CHILD(p) == NULL);
}

void printTreeRec(AddressTree p, int h) {
    // printf("print tree rec called\n");
    
    if (p != NULL) {
        int i;

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("| ID = %d\n", (p)->info.id);

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("| %s\n", (p)->info.author.TabWord);

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("| "); TulisDATETIME(p->info.date); printf("\n");

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("| %s\n", (p)->info.isi.TabWord);
        printf("\n");

        printTreeRec((p)->child, h+1);
        printTreeRec((p)->sibling,  h);
    }
}

// void printTree(Tree p, int h) {
//     printTreeRec(p, h);
// }

BALASAN* createBalasan(Word balasan, int idKicau){

    BALASAN *b = (BALASAN *)malloc(sizeof(BALASAN));
    (*b).author = KICAUAN_ELMT(ListKicauan, idKicau).Author;
    (*b).id = KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan;
    (*b).idAuthor = CurrentUserId;

    int long long currentTIme = getCurrentTime();
    (*b).date = DetikToDATETIME(currentTIme);
    (*b).isi = balasan;

    return b;
}

void addBalasan(AddressTree t, AddressTree *root){
    AddressTree p = *root;
    if(p == NULL){
        printf("p berniali null\n");
        *root = t;
    } else {
        printf("p ga null\n");
        while(CHILD(p) != NULL){
            p = CHILD(p);
        }
        CHILD(p) = t;
        printf("--------add BALASAN-------------\n");
        printf("%s\n", CHILD(p)->info.author.TabWord);
        TulisDATETIME(CHILD(p)->info.date);
        endl;
        printf("%d\n", CHILD(p)->info.id);
        printf("%s\n", CHILD(p)->info.isi.TabWord);
        printf("--------------------------------\n");
    }
}

void addBalasanSiblings(AddressTree t, AddressTree *root){
    AddressTree p = *root;
    if(p == NULL){
        printf("p berniali null\n");
        *root = t;
    } else {
        printf("p ga null\n");
        while(SIBLING(p) != NULL){
            p = SIBLING(p);
        }
        SIBLING(p) = t;
        printf("--------add BALASAN-------------\n");
        printf("%s\n", SIBLING(p)->info.author.TabWord);
        TulisDATETIME(SIBLING(p)->info.date);
        endl;
        printf("%d\n", SIBLING(p)->info.id);
        printf("%s\n", SIBLING(p)->info.isi.TabWord);
        printf("--------------------------------\n");
    }
}


void searchId(AddressTree kicauanUtama, int id_balasan, AddressTree* result){
    if (kicauanUtama == NULL) {
        // printf("kicauanUtama null\n");
        return ;
    }

    // cek siblings

    if ((kicauanUtama)->info.id == id_balasan){
        *result = kicauanUtama;
        return;
    }

    searchId((kicauanUtama)->sibling, id_balasan, result);

    // cek childs
    searchId((kicauanUtama)->child, id_balasan, result);
}

void searchIdParent(AddressTree kicauanUtama, int id_balasan, AddressTree* result, int* X){
    if (kicauanUtama == NULL) {
        printf("kicauanUtama null\n");
        return ;
    }

    
    // cek siblings

    if (CHILD(kicauanUtama) != NULL && CHILD(kicauanUtama)->info.id == id_balasan){
        printf("kicauanUtama = dengan id_balasan \n");
        *result = kicauanUtama;
        *X = 1;
        return;
    } else if (SIBLING(kicauanUtama) != NULL && SIBLING(kicauanUtama)->info.id == id_balasan){
        printf("kicauanUtama = dengan id_balasan \n");
        *result = kicauanUtama;
        *X = 2;
        return;
    }

    searchId((kicauanUtama)->sibling, id_balasan, result);

    // cek childs
    searchId((kicauanUtama)->child, id_balasan, result);
}

void insertBalasan(int idKicau, int idBalasan, AddressTree node){
    // int id_balasan = idBalasan;

    // printf("isi id_balasan %d\n", idBalasan);
    AddressTree *kicauanUtama = &KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;

    AddressTree root = NULL;
    searchId(*kicauanUtama, idBalasan, &root);


    if (idBalasan == -1){
        // printf("yey pertama\n");
        if(node->info.id == 0){
            // printf("root bernilai null\n");
            *kicauanUtama = node;
        } else {
            // printf("root not null\n");
            AddressTree p = *kicauanUtama;
            while(SIBLING(p) != NULL){
                p = SIBLING(p);
            }
            SIBLING(p) = node;
        }
        balasanKicauanDetail(*kicauanUtama);
    } else {
        if (root != NULL){
            if(CHILD(root) == NULL){
                CHILD(root) = node;
            } else {
                AddressTree newP = CHILD(root);
                while(SIBLING(newP) != NULL){
                    newP = SIBLING(newP);
                }
                SIBLING(newP) = node;
            }
        }
    }


    // -------------------- BALASAN SUDAH BERHASIL DITAMBAHKAN -------------
    
    KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan++;
    // printf("current inc_balasan: %d\n",KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan);


}

boolean balasValid(int idKicau, Word idBalasan){
    // validasi input
    if(!(idKicau >= 0 && idKicau < ListKicauan.NEFF)){
        printf("%s[id kicau] berada diluar batas kicauan%s\n", RED, NORMAL);
        return false;
    }

    int temp222222 = WordToInt(idBalasan);
    AddressTree found = NULL; 
    searchId(KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan, temp222222, &found);
    int idAuthorKicauan = KICAUAN_ELMT(ListKicauan, idKicau).idAuthor;
    if(temp222222 != -1 && found == NULL){
        printf("%s[id balasan] berada diluar batas kicauan%s\n", RED, NORMAL);
        return false;
    }

    // validasi apakah mereka private atau tidak
    if(isPrivat(idAuthorKicauan) && !isTeman(CurrentUserId, idAuthorKicauan)){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return false;
    }
    return true;
}

void balas(int idKicau, Word idBalasan){

    if (!balasValid(idKicau, idBalasan)){
        return ;
    }
    
    // masuk ke fungsi

    printf("Masukkan balasan:\n");
    Word balasan;
    readWord(&balasan, ';');

    BALASAN* b = createBalasan(balasan, idKicau);
    // -------------- ADD BALASAN ----------------- //

    AddressTree t = newTreeNode(b);

    printf("\n");
    printf("Selamat! balasan telah diterbitkan!\n");
    printf("Detail balasan:\n");

    insertBalasan(idKicau, WordToInt(idBalasan), t);

    // showDaftarBalasant(idKicau);
    // balasanKicauanDetail()
}

void balasanKicauanDetail(AddressTree p){
    if(p != NULL){
        printf("| ID = %d\n", p->info.id );
        printf("| %s\n", p->info.author.TabWord);
        printf("| "); TulisDATETIME(p->info.date); printf("\n");
        printf("| %s\n", p->info.isi.TabWord);
    }
}

void deallocTreeSection(AddressTree t){
    if(isOneElmt(t)){
        AddressTree p = t;
        printf("------------START-----------------\n");
        printf("| ID = %d\n", p->info.id );
        printf("| %s\n", p->info.author.TabWord);
        printf("| "); TulisDATETIME(p->info.date); printf("\n");
        printf("| %s\n", p->info.isi.TabWord);
        printf("------------END--------------------\n");

        t->child = NULL;
        t->sibling = NULL;
        free(t);
        return ;
    }

    deallocTreeSection(CHILD(t));
    
    deallocTreeSection(SIBLING(t));

    t->child = NULL;
    t->sibling = NULL;
    free(t);
    
}

boolean isHapusBalasanValid(int idKicau, int idBalasan){

    if(!(idKicau >= 0 && idKicau < ListKicauan.NEFF)){
        printf("%sMaaf tidak ditemukan balasan pada kicauan %s\n", RED, NORMAL);
        return false;
    }

    int temp222222 = idBalasan;
    AddressTree found = NULL; 
    searchId(KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan, temp222222, &found);
    // int idAuthorKicauan = KICAUAN_ELMT(ListKicauan, idKicau).idAuthor;
    if(temp222222 != -1 && found == NULL){
        printf("%sBalasan tidak ditemukan%s\n", RED, NORMAL);
        return false;
    }

    if (CurrentUserId != found->info.idAuthor){
        printf("%sMaaf, ini Balasan punya punya siapa? jangan di hapus!%s\n", RED, NORMAL);
        return false;
    }


    return true;

}

void hapusBalasan(int idKicau, int idBalasan){

    if (!isHapusBalasanValid(idKicau, idBalasan)){
        return ;
    }


    AddressTree* kicauanUtama = &KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;

    AddressTree root = NULL;
    searchId(*kicauanUtama, idBalasan, &root);

    AddressTree parent = NULL;
    int X = 0; // 1 = Child, 2 = Sibbling
    searchIdParent(*kicauanUtama, idBalasan, &parent, &X);

    if (parent == NULL)
    {
        *kicauanUtama = NULL;
        deallocTreeSection(root);
        return;
    }
    
    AddressTree p = parent;
    if(X == 1){ // child
        p = CHILD(p);
        CHILD(parent) = SIBLING(p);
    } else if(X == 2){ // sibling
        p = SIBLING(p);
        SIBLING(parent) = SIBLING(p);
        // CHILD(p) = NULL;
    }

    // printf("working till here\n");

    // printf("------------START-----------------\n");
    // printf("| ID = %d\n", p->info.id );
    // printf("| %s\n", p->info.author.TabWord);
    // printf("| "); TulisDATETIME(p->info.date); printf("\n");
    // printf("| %s\n", p->info.isi.TabWord);
    // printf("------------END--------------------\n");

    if(CHILD(p) != NULL)
        deallocTreeSection(CHILD(p));

    free(p);
    // root
}

boolean isBalasanValid(int idKicau){
    if(!(idKicau >= 0 && idKicau < ListKicauan.NEFF)){
        printf("%sTidak terdapat kicauan dengan id tersebut!%s\n", RED, NORMAL);
        return false;
    }

    int idAuthorKicauan = KICAUAN_ELMT(ListKicauan, idKicau).idAuthor;

    if(isPrivat(idAuthorKicauan) && !isTeman(CurrentUserId, idAuthorKicauan)){
        printf("%sWah, akun tersebut merupakan akun privat!%s\n", RED, NORMAL);
        return false;
    }

    int temp222222 = KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan;
    if(temp222222 == 0){
        printf("^%sBelum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!%s\n", RED, NORMAL);
        return false;
    }

    return true;
}

void showDaftarBalasant(int idKicau){
    if (!isBalasanValid(idKicau)){
        return;
    }

    AddressTree p = KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;
    printTreeRec(p, 2);
}