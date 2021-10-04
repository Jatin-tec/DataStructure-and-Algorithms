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
/* 
            10
          /   \
        20    30
      /   \
     40   Null
*/

int main(){
    
    struct Node *root = createNode(10);
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(30);
    struct Node *p12 = createNode(40);

    root->Left=p1;
    root->Right=p2;

    p1->Left=p12;


    PreOrderTraversal(root);
    printf("\n");
    InOrderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);
}