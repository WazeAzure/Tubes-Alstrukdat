
#include<stdio.h>
#include "pohontree.h"
#include "pohontree.c"

int main() {
    Tree tree = NULL; // initialize an empty tree

    // Test case 1: Creating a tree with root A and children B and C
    Tree child1 = newTreeNode('Ba');
    Tree child2 = newTreeNode('C');
    Tree child3 = newTreeNode('D');
    CreateTree('A', child1, &tree);
    NODE(tree) = 'A';
    CHILD(tree) = child1;
    SIBLING(child1) = child2;
    CHILD(child2) = child3;
    
    // Deallocate memory for the tree nodes
    deallocTreeNode(child1);
    deallocTreeNode(child2);

    return 0;
}