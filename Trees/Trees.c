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

    return node;    
}

void PreOrderTraversal(struct Node *Parent){

    if(Parent!=NULL){
        
        printf("%d\t", Parent->data);

        PreOrderTraversal(Parent->Left);
        PreOrderTraversal(Parent->Right);
    }

}

void PostOrderTraversal(struct Node *Parent){
    
    if(Parent!=NULL){
        
        PostOrderTraversal(Parent->Left);
        PostOrderTraversal(Parent->Right);
        
        printf("%d\t", Parent->data);
    }    
}

void InOrderTraversal(struct Node *Parent){

      if(Parent!=NULL){
        
        InOrderTraversal(Parent->Left);
        printf("%d\t", Parent->data);
        InOrderTraversal(Parent->Right);
        
    }   
}

int main(){
    
    struct Node *root = createNode(root, 10);
    struct Node *p1 = createNode(p1, 20);
    struct Node *p2 = createNode(p2, 30);
    struct Node *p12 = createNode(p12, 40);

    root->Left=p1;
    root->Right=p2;

    p1->Left=p12;
    p1->Right=NULL;

    p2->Left=NULL;
    p2->Right=NULL;

    p12->Left=NULL;
    p12->Right=NULL;

    InOrderTraversal(root);

}