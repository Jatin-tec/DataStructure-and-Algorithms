#include<stdio.h>

void Print(int *Ar, int size){
        
    for (int k=0; k<size; k++){
        printf("%d ", Ar[k]);
    }
    
}

void BubbleSort(int *Ar, int size){
    int swap;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1-i; j++){
            if(Ar[j]>Ar[j+1]){
                swap=Ar[j];
                Ar[j]=Ar[j+1];
                Ar[j+1]=swap;
            }
        }
    }
    
}

int main(){

    int Ar[] = {10, 7, 23, 13 , 22, 53};
    int size = sizeof(Ar)/sizeof(int);

    printf("Before sort \n");
    
    Print(Ar, size);
    
    printf("\nAfter sort \n");

    BubbleSort(Ar, size);

    Print(Ar, size);
}