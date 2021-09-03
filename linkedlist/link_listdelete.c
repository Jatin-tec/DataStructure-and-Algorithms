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
        ptr=ptr->next;
    }
    
}

struct Node *DeleteFirst(struct Node *ptr){
    struct Node *head;
    head = ptr->next;
    free(ptr);
    return head;
}

struct Node *DeleteLast(struct Node *head){
    struct Node *p;
    struct Node *q;

    p=head;
    q=head->next;
    while (q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node *DeleteIndex(struct Node *head, int index){
    struct Node *p;
    struct Node *q;
    
    p = head;
    q = head->next;

    int i=0;
    
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    
    p->next=q->next;

    free(q);
    
    return head;
}

struct Node *DeleteNode(struct Node *head, struct Node *ptr){
    struct Node *p;
    struct Node *q;

    p = head;
    q = head->next;

    while(q!=ptr){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
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

    printf("Before deletion \n");
    Travel(head);

    printf("After deletion \n");
    head = DeleteNode(head, third);
    Travel(head);
}