#include "pohontree.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../globalVar.h"
#include "../Wordmachine/charmachine.h"
#include "../Wordmachine/wordmachine.h"

Tree NewTree(ElTypeTree root, Tree firstChild) {
    Tree newTree = (Tree)malloc(sizeof(TreeNode));
    if (newTree != NULL) {
        NODE(newTree) = root;
        CHILD(newTree) = firstChild;
        SIBLING(newTree) = NULL;
    }
    return newTree;
}

void CreateTree(ElTypeTree root, Tree firstChild, Tree *p) {
    *p = NewTree(root, firstChild);
}

AddressTree newTreeNode(ElTypeTree val) {
    AddressTree newNode = (AddressTree)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        NODE(newNode) = val;
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

boolean isUner(Tree p) {
    return (p != NULL && CHILD(p) != NULL && SIBLING(CHILD(p)) == NULL);
}

boolean isBinary(Tree p) {
    return (p != NULL && (CHILD(p) == NULL || SIBLING(CHILD(p)) != NULL));
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

BALASAN createBalasan(Word balasan, int idKicau){

    BALASAN b;
    b.author = KICAUAN_ELMT(ListKicauan, idKicau).Author;
    b.id = KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan;
    b.idAuthor = CurrentUserId;

    int long long currentTIme = getCurrentTime();
    b.date = DetikToDATETIME(currentTIme);
    b.isi = balasan;

    return b;
}

void addBalasan(AddressTree t, AddressTree *root){
    printf("add balasan dipanggil\n");

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
    }
}

AddressTree* searchIdBalasan(AddressTree* kicauanUtama, int idBalasan){
    AddressTree *p = kicauanUtama;
    printf("\nroot utama id%d\n", (*p)->info.id);
    printf("\nroot utama author%s\n", (*p)->info.author.TabWord);
    if (p != NULL) {
        printf("p ga null\n");
        printf("%d idBalasan\n", idBalasan);
        if((*p)->info.id == idBalasan){
            return &((*p)->sibling);
        }

        AddressTree *result = NULL;
        if(SIBLING(*p) != NULL){
            result = searchIdBalasan(&SIBLING(*p), idBalasan);
            if(result != NULL || result != kicauanUtama){
                return &((*result)->sibling);
            }
            
        }

        if(CHILD(*p) != NULL){
            result = searchIdBalasan(&CHILD(*p), idBalasan);
            if(result != NULL || result != kicauanUtama){
                return &((*result)->sibling);
            }
        }
        return result;
    }
    printf("p null\n");
    return kicauanUtama;
}

void balas(int idKicau, Word idBalasan){
    printf("Masukkan balasan:\n");
    Word balasan;
    readWord(&balasan, ';');

    BALASAN b = createBalasan(balasan, idKicau);
    // printf("%s\n", b.author.TabWord);
    
    AddressTree* kicauanUtama = &KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;

    AddressTree t = newTreeNode(b);
    
    if(strCompare(idBalasan.TabWord, "-1")){
        addBalasan(t, kicauanUtama);
    } else {
        int idBalasanInt = WordToInt(idBalasan);
        AddressTree* newRoot = searchIdBalasan(kicauanUtama, idBalasanInt);
        addBalasan(t, newRoot);
    }

    KICAUAN_ELMT(ListKicauan, idKicau).inc_balasan++;

    // printf("sampe sini berhasil\n");

    if(ListKicauan.buffer[idKicau].daftar_balasan == NULL){
        printf("null cuy\n");
    }

    AddressTree p = KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;
    while(p != NULL){
        printf("%s\n", p->info.author.TabWord);
        TulisDATETIME(p->info.date);
        printf("%s\n", p->info.isi.TabWord);
        p = CHILD(p);
    }
    
    printf("--------------------------------\n\n");
    p = KICAUAN_ELMT(ListKicauan, idKicau).daftar_balasan;
    printTreeRec(&p, 2);
}