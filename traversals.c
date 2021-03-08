#include "tree.h"
#include <stdio.h>


void inOrderPrint(node*root) {
    if (root!=NULL) {
        inOrder(root->left);
        printf("value of node is %d\n",root->key);
        inOrder(root->right);
    }
}

void preOrderPrint(node*root, int d) {
    if (root!=NULL) {
        printf("value of node is %d d=%d\n",root->key,d);
        preOrder(root->left,d+1);
        preOrder(root->right,d+1);
    }
}
 
node* inOrderSuccesorParent(node*root) {
    if (root->left->left==NULL) return root->left;
    return inOrderSuccesorParent(root->left);
}

node* getInOrderSuccesor(node*root) {
    return inOrderSuccesor(root->right);
}


