#include <stdio.h>

void Print(int *Ar, int size){
        
    for (int k=0; k<size; k++){
        printf("%d ", Ar[k]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a  = *b;
    *b = temp;

}

void heapify(int Arr[], int size, int max){

    int largest = max;
    int left = 2*max + 1; 
    int right = 2*max + 2;

    if(right<size && Arr[largest]<Arr[right]){
        largest=right;
    } 

    if(left<size && Arr[largest]<Arr[left]){
        largest=left;
    } 
    
    if(largest != max){
        swap(&Arr[largest], &Arr[max]);
        heapify(Arr, size, largest);
    }

}

//  left child can be calculated by 2 * I + 1 i.e. odd positions
//  and the right child by 2 * I + 2 (assuming the indexing starts at 0)

void heapSort(int Arr[], int size){

    for (int i = (size/2)-1; i >= 0; i--) //reversing it because we want to lowest and right parent (if exist)
                                         //to be bigger than its child node value                               
    {
        heapify(Arr, size, i);
    }
    Print(Arr, size);

    for (int j = size-1; j > 0; j--)
    {
        swap(&Arr[0], &Arr[j]);
        Print(Arr, size);
        heapify(Arr, j, 0);    
    }
    
    

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
