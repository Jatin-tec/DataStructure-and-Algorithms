#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *Right;
    struct Node *Left;
};

struct Node *createNode(struct Node *ptr, int data){
    
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

void DeleteNode(struct Node *root, int key){
    struct Node *prev = NULL;

    if(root!=NULL){
        
    }
}

int main(){
    
    struct Node *root = createNode(root, 8);
    struct Node *p1 = createNode(p1, 3);
    struct Node *p2 = createNode(p2, 18);
    struct Node *p11 = createNode(p11, 1);
    struct Node *p12 = createNode(p12, 6);
    struct Node *p121 = createNode(p121, 4);
    struct Node *p122 = createNode(p122, 7);
    struct Node *p22 = createNode(p22, 14);
    struct Node *p221 = createNode(p221, 13);

/*           8    
           /   \ 
          3     18  
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

}