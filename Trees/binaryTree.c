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

struct Node *Search(struct Node *root, int element){
    
    if(root==NULL){
        printf("Element not found!!");
    }
    
    if(element==root->data){
        printf("Element found!!");
        return root;
    }

    if(element < root->data){
       Search(root->Left, element);
       return root; 
    }

    else
        Search(root->Right, element);   
        return root; 
}

struct Node *IterativeSearch(struct Node *root, int element){

    while (root!=NULL)
    {
        if(element==root->data){
            printf("Element found!!");
            return root;
        }
        if(element<root->data){
            root=root->Left;
        } 
        else
            root=root->Right; 
    }
    if(root==NULL){
        printf("Element not Found!!");
    }    
}

void Insert(struct Node *Parent, int key){
    struct Node *prev=NULL;
    while (Parent!=NULL){
        prev=Parent;
        if(key==Parent->data){
            printf("Element exist already!");
            return;
        }
        else if(key<Parent->data){
            Parent=Parent->Left;
        }
        else{
            Parent=Parent->Right;
        }
    }
    struct Node *Insert = createNode(Insert, key);
    Insert->data=key;
    if(key<prev->data){
        prev->Left=Insert;
    }
    else
        prev->Right=Insert;
}

void RecursiveInsert(struct Node *Parent, int key){
    static struct Node *prev=NULL;

    if(Parent!=NULL){
        if(key==Parent->data){
            printf("Element already Exist!!");
        }
        prev=Parent;
        if(key<=Parent->data){
            RecursiveInsert(Parent->Left, key);
        }
        else
            RecursiveInsert(Parent->Right, key);
    }    
    struct Node *RInsert = createNode(RInsert, key);
    if(key<prev->data){
        prev->Left=RInsert;
    }
    else
        prev->Right=RInsert;
        
}

int main(){
    
    struct Node *root = createNode(root, 10);
    struct Node *p1 = createNode(p1, 7);
    struct Node *p2 = createNode(p2, 12);
    struct Node *p11 = createNode(p11, 4);
    struct Node *p12 = createNode(p12, 9);

/*           10    
           /    \ 
          7      12   
         / \ 
        4   9
*/
    
    root->Left=p1;
    root->Right=p2;

    p1->Left=p11;
    p1->Right=p12;

    // InOrderTraversal(root);
    // IterativeSearch(root, 1);

    // printf("\n%d", IsBinary(root));

    RecursiveInsert(root, 11);
    InOrderTraversal(root);

}