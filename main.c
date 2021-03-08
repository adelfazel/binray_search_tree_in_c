#include <stdio.h>
#include "tree.h"
int main() {
    node* root=treeInsert(NULL,10);
    treeInsert(root,20);
    treeInsert(root,30);
    treeInsert(root,40);
    treeInsert(root,35);
    treeInsert(root,3);
    treeInsert(root,15);
    printf("In order\n");
    inOrder(root);
    printf("Pre order\n");
    preOrder(root,1);
    return 0;
}