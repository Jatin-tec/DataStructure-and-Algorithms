#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *Right;
    struct Node *Left;
};

struct Node *createNode(int data){
    
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));

    node->data=data;
    node->Left=NULL;
    node->Right=NULL;

    return node;    
}

void InOrderTraversal(struct Node *Parent){

      if(Parent!=NULL){
        
        InOrderTraversal(Parent->Left);
        printf("%d\t", Parent->data);
        InOrderTraversal(Parent->Right);
    }   
}

int IsBinary(struct Node *Parent){
    static struct Node *prev = NULL;

    if(Parent!=NULL){
        //If left sub tree is not BST the tree is not BST
        if(!IsBinary(Parent->Left)){
            return 0;
        }
        //If its not root node and prev data is greater than the current one => the
        //InOrderTraversal is not in assending order   
        if(prev!=NULL && Parent->data <= prev->data){
            return 0;
        }
        prev = Parent;
        //Applying same to the right sub tree
        IsBinary(Parent->Right);
    }
    else{
        return 1;
    }
} 

struct Node *findInOrder_pre(struct Node *root){
    root = root->Left;
    while (root->Right != NULL)
    {
        root = root->Right;
    }
    return root;
}

struct Node *DeleteNode(struct Node *root, int key){
    struct Node *preOrd;
    
    if(root==NULL){
        return NULL;
    }

    if(root->Left==NULL && root->Right==NULL){
        free(root);
        return NULL;
    }

    //Searching node we have to delete
    if(root->data<key){
        DeleteNode(root->Right, key);
    }

    else if(root->data>key){
        DeleteNode(root->Left, key);
    }

    else
    {
        preOrd = findInOrder_pre(root);
        root->data = preOrd->data;
        root->Left = DeleteNode(root->Left, preOrd->data);
    }
    return root;
}

int main(){
    
    struct Node *root = createNode(8);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(12);
    struct Node *p11 = createNode(1);
    struct Node *p12 = createNode(6);
    struct Node *p121 = createNode(4);
    struct Node *p122 = createNode(7);
    struct Node *p22 = createNode(14);
    struct Node *p221 = createNode(13);

/*           8    
           /   \ 
          3     12  
         / \      \
        1   6      14
           / \    /
          4   7  13
*/
    
    root->Left=p1;
    root->Right=p2;

    p1->Left=p11;
    p1->Right=p12;

    p12->Left=p121;
    p12->Right=p122;

    p2->Right=p22;

    p22->Left=p221;

    InOrderTraversal(root);
    DeleteNode(root, 6);
    printf("\n");
    InOrderTraversal(root);

}