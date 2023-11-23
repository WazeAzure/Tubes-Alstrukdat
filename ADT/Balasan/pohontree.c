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

void printTreeRec(Tree *p, int h) {
    printf("print tree rec called\n");
    
    if (*p != NULL) {
        int i;

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("%d\n", (*p)->info.id);

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("%s\n", (*p)->info.author.TabWord);

        for (i = 0; i < h*2; i++) {
            printf("  ");
        }
        printf("%s\n", (*p)->info.isi.TabWord);

        printTreeRec(&(*p)->sibling,  h+1);
        printTreeRec(&(*p)->child, h);
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

// AddressTree* searchIdBalasan(AddressTree* kicauanUtama, int idBalasan){
//     AddressTree *p = kicauanUtama;
//     printf("\nroot utama id %d\n", (*p)->info.id);
//     printf("root utama author %s\n", (*p)->info.author.TabWord);
    
//     if (p != NULL) {
//         printf("p ga null\n");
//         printf("%d idBalasan\n", idBalasan);
//         printf("%d\n", (*p)->info.id);
//         if((*p)->info.id == idBalasan){
//             printf("return sibling called\n");
//             return p;
//         }
//         printf("ga return sibling called\n");


//         AddressTree *result = NULL;
//         if(SIBLING(*p) != NULL){
//             result = searchIdBalasan(SIBLING(*p), idBalasan);
//             if(result != NULL || result != kicauanUtama){
//                 return result;
//             }
            
//         }

//         if(CHILD(*p) != NULL){
//             result = searchIdBalasan(CHILD(*p), idBalasan);
//             if(result != NULL || result != kicauanUtama){
//                 return result;
//             }
//         }
//         return result;
//     }
//     printf("p null\n");
//     return kicauanUtama;
// }

// void searchIdBalasan(AddressTree* kicauanUtama, int idBalasan, AddressTree* ans) 
// { 
//     if (node == NULL) 
//         return; 
  
//     /* first recur on left child */
//     printInorder(node->left); 
  
//     /* then print the data of node */
//     printf("%d ", node->data); 
  
//     /* now recur on right child */
//     printInorder(node->right); 
// } 

void insertBalasan(int idKicau, Word idBalasan, AddressTree node){
    int id_balasan = WordToInt(idBalasan);
    printf("isi id_balasan %d\n", id_balasan);
    AddressTree* kicauanUtama = &KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;

    AddressTree* root = searchId(kicauanUtama, idBalasan);

    if (id_balasan == -1){
        
    } else {

    }


    // -------------------- BALASAN SUDAH BERHASIL DITAMBAHKAN -------------
    
    KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan++;
    printf("current inc_balasan: %d\n",KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan);

    if(ListKicauan.buffer[idKicau].daftar_balasan == NULL){
        printf("null cuy\n");
    }


    printf("Selamat! balasan telah diterbitkan!\n");
    printf("Detail balasan\n");

    balasanKicauanDetail(t);
}

void balas(int idKicau, Word idBalasan){
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
}

void balasanKicauanDetail(AddressTree p){
    if(p != NULL){
        printf("| ID = %d\n", p->info.id );
        printf("| %s\n", p->info.author.TabWord);
        printf("| "); TulisDATETIME(p->info.date); printf("\n");
        printf("| %s\n", p->info.isi.TabWord);
    }
}

void showDaftarBalasant(int idKicau){

    AddressTree p = KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;
    
    printf("\n\n");
    p = KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;
    printTreeRec(&p, 2);
}