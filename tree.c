#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

node* createNewNode(int key){
    node* n=malloc(sizeof(node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
}

