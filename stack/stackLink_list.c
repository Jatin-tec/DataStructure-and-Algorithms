#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isFull(struct Node *ptr){
    if(ptr==NULL){
        return 1;
    }
    return 0;
}

int isEmpty(struct Node *ptr){
    if(ptr==NULL){
        return 1;
    }
    return 0;
}

void travel(struct Node *ptr){

    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
}

struct Node *push(struct Node *top, int val){
    struct Node *insert;
    insert = (struct Node*) malloc(sizeof(struct Node));
    if(isFull(insert)){
        printf("StackOverflow!!");
    }
    else if(top==NULL){
        insert->data=val;
        insert->next=NULL;
    }
    else{    
        insert->data=val;
        insert->next=top;
    }
    return insert;
}

int pop(struct Node **top){
    if(isEmpty(*top)){
        printf("StackUnderflow!");
    }
    struct Node *temp;
    temp=(*top)->next;

    int x=(*top)->data;
    free(*top);
    *top=temp;
    return x;   
}

int main(){
    struct Node *top;
    
    top = (struct Node*) malloc(sizeof(struct Node));
    top=NULL;
    top=push(top, 10);
    top=push(top, 20);
    top=push(top, 30);
    printf("Before pop\n");
    travel(top);
    int element=pop(&top);
    printf("After poping  %d\n", element);
    travel(top);
}