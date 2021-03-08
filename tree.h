
typedef struct node {
        int key;
        node* left,right;
} node;

node* treeInsert(node*root, int v);
node* delete_key(node*root, int key);
void inOrderPrint(node* root); 
void preOrderPrint(node* root,int depth); 
void postOrderPrint(node* root,int depth); 
node* inOrderSuccesorParent(node*root);
node* search(node*root,int);


