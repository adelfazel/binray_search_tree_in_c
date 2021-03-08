#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

node* search(node*root,int key) {
    if (root==NULL) return NULL;
    if (root->key==key) return root; 
    if (key<root->key) 
        return search(root->left,key);
    return search(root->right,key);    
}

node* createNewNode(int key){
    node* n=malloc(sizeof(node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    return n;
}

node* treeInsert(node*root, int key) {
    if (root==NULL) {
        root=createNewNode(key);
        return root;
    }
    if (root->key==key)
        return NULL;
    if (key<root->key)
        if (root->left==NULL) {
           root->left=createNewNode(key);
           return root->left;
        }
        else return treeInsert(root->left,key);    
    else if (root->right==NULL) {
           root->right=createNewNode(key);
           return root->right;
        }
        else return treeInsert(root->right,key); 
}

bool is_leaf(node*root) {
    return (root->right==NULL && root->left==NULL);
}

node* handle_root_equal_key(node*root) {
    node* equalNode;
    node* parentOfEqualNode;
    if (is_leaf(root)) {
        free(root);
        return NULL;
    } else if (root->left==NULL) {
        equalNode=root->right;
        free(root);
        return equalNode;
    } else if (root->right==NULL) {
        equalNode=root->left;
        free(root);
        return equalNode;
    } else {
        parentOfEqualNode=inOrderSuccesorParent(root);
        equalNode=parentOfEqualNode->left;
        root->key=equalNode->key;
        if (equalNode->right==NULL) {
            free(equalNode);
            return root;
        } else {
            parentOfEqualNode->left=parentOfEqualNode->left->right;
            free(equalNode);
            return root;
        }
    }
}

void handle_root_not_equal_key(node* root,int key){
    node* equalNode,parentOfEqualNode;
    if(key<root->key) {
        equalNode=root->left;
        if (equalNode->key==key) {
            if (is_leaf(equalNode)) free(equalNode); else {
                if (equalNode->left == NULL) {
                    root->left=equalNode->right;
                    free(equalNode);    
                } else if (equalNode->right == NULL) {
                    root->left=equalNode->left;
                    free(equalNode);       
                } else {
                    parentOfEqualNode=inOrderSuccesorParent(equalNode);

                }
            }
        } else handle_root_not_equal_key(root->left,key);
    } else if (root->right->key==key) {
        
        
    } else handle_root_not_equal_key(root->right,key);
     

}

node* delete_key(node*root, int key) {
    if (root!=NULL) {
        if (root->key==key) {
            return handle_root_equal_key(root);
        } else {
            handle_root_not_equal_key(root,key);
            return root;
        }
    }
    return root;
}

