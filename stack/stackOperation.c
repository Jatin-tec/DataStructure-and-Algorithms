#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int *Arr;
    int Top;
    int Size;
};

int IsEmpty(struct Stack *s){
    if(s->Top==-1){
        return 1;
    }
    return 0;
}

int IsFull(struct Stack *s){
    if(s->Top==s->Size-1){
        return 1;
    }
    return 0;
}

void push(struct Stack *s, int num){
    if(IsFull(s)){
        printf("Stack is Overflow!!\n");
    }
    s->Top++;
    s->Arr[s->Top]=num;
    printf("Element pushed sucessfully\n");
}

int pop(struct Stack *s){
    if(IsEmpty(s)){
        printf("Stack Underflow!!\n");
    }
    int temp = s->Arr[s->Top];
    s->Top--;
    printf("Element poped sucessfully\n");
    return temp;
}

int main(){
    struct Stack *s = (struct Stack*) malloc(sizeof(struct Stack)) ;
    s->Top=-1;
    s->Size=10;
    
    s->Arr = (int*) malloc(s->Size*sizeof(struct Stack));
    
    for(int i=0; i<4; i++){
        push(s, i*10);
    }
    for(int i=0; i<4; i++){
        printf("%d\n", s->Arr[i]);
    }
    pop(s);
        for(int i=0; i<3; i++){
        printf("%d\n", s->Arr[i]);
    }
}
