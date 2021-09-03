#include<stdio.h>

int LinerSerch(int Arr[], int size, int element){
    printf("This is linear search");
    for(int i=0; i<size; i++){
        if(Arr[i]==element){
            printf("\nElement %d Index %d",element, i);
        }
    }
    return -1;
}

int BinarySearch(int Arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    printf("\nThis is binary search ");
    while (low<=high)
    {
        mid = (low+high)/2;

        if(element==Arr[mid]){
            printf("\nElement %d Index %d",element, mid);
        }
        if(element>Arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    } 
    return -1;  
}
int main(){

    int Arr[]={1, 4, 5, 8, 14, 39, 40 , 77};
    int size = sizeof(Arr)/sizeof(int);
    int element = 14;
    LinerSerch(Arr, size, element);
    BinarySearch(Arr, size, element);

}