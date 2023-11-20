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

void deleteNode(Tree *p, ElType val) {
    Address parent = NULL;
    Address current = *p;

    // Find the node to be deleted and its parent
    while (current != NULL && NODE(current) != val) {
        parent = current;
        current = SIBLING(current);
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", val);
        return;
    }

    if (parent != NULL) {
        SIBLING(parent) = SIBLING(current); // Remove the node from the siblings
    } else {
        *p = SIBLING(current); // If the node to be deleted is the root
    }

    deallocTreeNode(current); // Deallocate memory for the node

    // Recursively delete the children of the node
    Address child = CHILD(current);
    while (child != NULL) {
        Address nextChild = SIBLING(child); // Save next child before deletion
        deleteNode(&child, NODE(child)); // Recursive call to delete children
        child = nextChild; // Move to the next child
    }
}

