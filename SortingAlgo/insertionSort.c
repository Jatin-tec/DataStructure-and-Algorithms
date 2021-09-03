#include<stdio.h>

// is stable
// space complexity is less
// is adaptive

void Print(int *Ar, int size){
        
    for (int k=0; k<size; k++){
        printf("%d ", Ar[k]);
    }
    printf("\n");
}

void InsertionSort(int *Ar, int size){
    int swap;
    int new;

    for (int i = 0; i < size-1; i++){
        new = Ar[i+1];
        for (int j = 0; j< i+1; j++){

            if(new < Ar[j]){
                swap=Ar[i+1];
                Ar[i+1]=Ar[j];
                Ar[j]=swap; 
            }
        }    
            Print(Ar, size);       
    }
}

int main(){

    int Ar[] = {10, 7, 21 , 22, 23, 24, 2, 0};
    int size = sizeof(Ar)/sizeof(int);

    printf("Before sort \n");
    
    Print(Ar, size);
    
    printf("\nAfter sort \n");

    InsertionSort(Ar, size);

    Print(Ar, size);
}