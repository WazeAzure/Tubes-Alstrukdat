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
        printf("%d\n", (p)->info.id);

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("%s\n", (p)->info.author.TabWord);

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("%s\n", (p)->info.isi.TabWord);

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
        printf("kicauanUtama null\n");
        return ;
    }

    // cek siblings

    if ((kicauanUtama)->info.id == id_balasan){
        printf("kicauanUtama = dengan id_balasan \n");
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



void insertBalasan(int idKicau, Word idBalasan, AddressTree node){
    int id_balasan = WordToInt(idBalasan);
    if(strCompare(idBalasan.TabWord, "-1")){
        id_balasan = -1;
    }
    printf("isi id_balasan %d\n", id_balasan);
    AddressTree *kicauanUtama = &KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;

    AddressTree root = NULL;
    searchId(*kicauanUtama, id_balasan, &root);


    if (id_balasan == -1){
        printf("yey pertama\n");
        if(node->info.id == 0){
            printf("root bernilai null\n");
            *kicauanUtama = node;
            balasanKicauanDetail(*kicauanUtama);
        } else {
            printf("root not null\n");
            AddressTree p = *kicauanUtama;
            while(SIBLING(p) != NULL){
                p = SIBLING(p);
            }
            SIBLING(p) = node;
        }
    } else {
        if (root != NULL){
            printf("dalam else, root not null\n");
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
    printf("current inc_balasan: %d\n",KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan);

    // if(ListKicauan.buffer[idKicau].daftar_balasan == NULL){
    //     printf("null cuy\n");
    // }


    printf("Selamat! balasan telah diterbitkan!\n");
    printf("Detail balasan\n");

    // balasanKicauanDetail(t);
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

    printf("--------------------------------\n");
    printf("%s\n", b->author.TabWord);
    TulisDATETIME(b->date);
    endl;
    printf("%d\n", b->id);
    printf("%s\n", b->isi.TabWord);
    printf("--------------------------------\n");

    // -------------- ADD BALASAN ----------------- //

    AddressTree t = newTreeNode(b);

    printf("--------------TREEE NODE-------------\n");
    printf("%s\n", t->info.author.TabWord);
    TulisDATETIME(t->info.date);
    endl;
    printf("%d\n", t->info.id);
    printf("%s\n", t->info.isi.TabWord);
    printf("--------------------------------\n");

    insertBalasan(idKicau, idBalasan, t);

    showDaftarBalasant(idKicau);
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
    if(t == NULL){
        return ;
    }

    deallocTreeSection(CHILD(t));
    deallocTreeSection(SIBLING(t));

    // AddressTree p = t;
    // printf("--------add BALASAN-------------\n");
    // printf("%s\n", CHILD(p)->info.author.TabWord);
    // TulisDATETIME(CHILD(p)->info.date);
    // endl;
    // printf("%d\n", CHILD(p)->info.id);
    // printf("%s\n", CHILD(p)->info.isi.TabWord);
    // printf("--------------------------------\n");

    // t->child = NULL;
    // t->sibling = NULL;
    free(t);
    
}

void hapusBalasan(int idKicau, int idBalasan){
    AddressTree* kicauanUtama = &KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;

    AddressTree root = NULL;
    searchId(*kicauanUtama, idBalasan, &root);

    AddressTree parent;
    int X = 0; // 1 = Child, 2 = Sibbling
    searchIdParent(*kicauanUtama, idBalasan, &parent, &X);


    printf("working till here -----------\n");

    AddressTree p = parent;
    if(X == 1){
        p = CHILD(p);
        CHILD(parent) = SIBLING(p);
        SIBLING(p) = NULL;
    } else if(X == 2){
        p = SIBLING(p);
        SIBLING(parent) = SIBLING(p);
        CHILD(p) = NULL;
    }

    printf("working till here\n");

    deallocTreeSection(CHILD(p));

    free(p);
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
    // printf("\n\n");
    // p = KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;
    printTreeRec(p, 2);
}