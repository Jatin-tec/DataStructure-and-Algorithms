#include<stdio.h>

void Print(int *Ar, int size){
        
    for (int k=0; k<size; k++){
        printf("%d ", Ar[k]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int c;
    
    c=*a;
    *a=*b;
    *b=c;
}

void shellSort(int Arr[], int size){
    int interval = size/2;
    int i;

    while (interval>0)
    {
        i=interval;
        while(i<size){
            if (Arr[i-interval]>Arr[i]){
                swap(&Arr[i-interval], &Arr[i]);
            }
            i++;
        }    
        interval /= 2;
    }
    
}

int main(){

    int Ar[] = {10, 7, 21 , 22, 23, 24, 2, 0};
    int size = sizeof(Ar)/sizeof(int);

    printf("Before sort \n");
    
    Print(Ar, size);
    
    printf("\nAfter sort \n");

    shellSort(Ar, size);

    Print(Ar, size);
}
