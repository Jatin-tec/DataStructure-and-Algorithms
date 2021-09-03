#include<stdio.h>


// not stable
// not adaptive

void Print(int *Ar, int size){
        
    for (int k=0; k<size; k++){
        printf("%d ", Ar[k]);
    }
    printf("\n");
}

void SelectionSort(int *Ar, int size){
    int minIndex;
    int swapIndex;
    int swap;
    for (int i = 0; i < size-1; i++){
        swapIndex = i;
        minIndex = i;
        for (int j = i; j< size; j++){
            if(Ar[minIndex]>Ar[j]){
                minIndex = j;
            }
            swap = Ar[swapIndex];
            Ar[swapIndex] = Ar[minIndex];
            Ar[minIndex] = swap;

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

    SelectionSort(Ar, size);

    Print(Ar, size);
}