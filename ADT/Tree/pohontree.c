#include "pohontree.h"
#include <stdio.h>
#include <stdlib.h>

Tree NewTree(ElType root, Tree firstChild) {
    Tree newTree = (Tree)malloc(sizeof(TreeNode));
    if (newTree != NULL) {
        NODE(newTree) = root;
        CHILD(newTree) = firstChild;
        SIBLING(newTree) = NULL;
    }
    return newTree;
}

void CreateTree(ElType root, Tree firstChild, Tree *p) {
    *p = NewTree(root, firstChild);
}

Address newTreeNode(ElType val) {
    Address newNode = (Address)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        NODE(newNode) = val;
        CHILD(newNode) = NULL;
        SIBLING(newNode) = NULL;
    }
    return newNode;
}

void deallocTreeNode(Address p) {
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

void printTreeRec(Tree p, int h) {
    if (p != NULL) {
        int i;
        for (i = 0; i < h; i++) {
            printf("  ");
        }
        printf("%c\n", NODE(p));
        printTreeRec(CHILD(p), h + 1);
        printTreeRec(SIBLING(p), h);
    }
}

void printTree(Tree p, int h) {
    printTreeRec(p, h);
}

