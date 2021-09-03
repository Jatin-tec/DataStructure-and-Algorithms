#include<stdio.h>

void show(int Arr[], int size){

    for(int i=0; i<size; i++){
        printf("%d ", Arr[i]);
        }
        printf("\n");
}

void insert(int Arr[], int value,int index, int size){
    for(int i=size; i>=index; i--){
        Arr[i]=Arr[i-1];
    }
    Arr[index] = value;
}

int main(){
    int Arr[100] = {1, 12, 54, 23, 13};
    int size=5;
    show(Arr, size);
    insert(Arr, 23, 2, size);
    size +=1;
    show(Arr, size);
    insert(Arr, 5, 4, size);
    size +=1;
    show(Arr, size);
}    