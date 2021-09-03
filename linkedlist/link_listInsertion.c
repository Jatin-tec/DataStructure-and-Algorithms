#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void Travel(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *InsertFirst(struct Node *ptr, int data){
   struct Node *insert;
   insert = (struct Node*) malloc(sizeof(struct Node));
   
   insert->data=data; 
   insert->next=ptr;

   return insert; 
}

struct Node *InsertIndex(struct Node *ptr, int index, int data){
    
    struct Node *insert;
    insert = (struct Node*) malloc(sizeof(struct Node));

    struct Node *head;
    head=ptr; 
    
    int i=0;

    while (i!=index-1)
    {
        ptr=ptr->next;
        i++;
    }
    
    insert->data = data;
    insert->next = ptr->next;
    ptr->next = insert; 

    return head;
}

struct Node *InsertEnd(struct Node *ptr, int data){

   struct Node *insert;
   insert = (struct Node*) malloc(sizeof(struct Node));
   
   struct Node *head;
   head = ptr;

   while (ptr->next!=NULL)
   {
       ptr=ptr->next;
   }
   insert->data=data;
   ptr->next = insert;
   insert->next = NULL;

   return head; 
}

struct Node *InsertNode(struct Node *ptr,struct Node *node , int data){
    struct Node *insert;
    insert = (struct Node*) malloc(sizeof(struct Node));
    struct Node *head=ptr;
    
    insert->data=data; 
    insert->next=node->next;
    node->next = insert;
    return head; 
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    printf("Before insertion\n");
    Travel(head);

    printf("After insertion\n");
    head=InsertFirst(head, 50);
    head=InsertFirst(head, 80);
    Travel(head);

}