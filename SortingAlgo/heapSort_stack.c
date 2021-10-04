#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * previous;
};

struct node *createNode (int value){
    struct node *Node = (struct Node*) malloc(sizeof(struct node));
    
    Node->data=value;
    Node->previous=NULL;
    Node->next=NULL;

    return Node;
}

int main()
{
    int Ar[] = {10, 7, 21 , 22, 23, 24, 2, 0};
    int size = sizeof(Ar)/sizeof(int);



    printf("Before sort \n");    
    Print(Ar, size);

    printf("\nAfter sort \n");
    heapSort(Ar, size);
    Print(Ar, size);

    return 0;
}

