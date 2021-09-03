#include <stdio.h>
#include <stdlib.h>

void Print(int *Ar, int size)
{

    for (int k = 0; k < size; k++)
    {
        printf("%d ", Ar[k]);
    }
    printf("\n");
}

void countSort(int Ar[], int size)
{
    int *count;
    count = (int *)malloc(sizeof(int) * 10);
    
    // initializing each value of count to 0 
    for (int j = 0; j < 10; j++)
    {
        count[j] = 0;
    }

    // incrementing values according to their occurence
    for (int i = 0; i < size; i++)
    {
        count[Ar[i]]++;
    }

    int arrayIndex = 0;
    int countIndex = 0;
    while (countIndex < 10)
    {
        if (count[countIndex] > 0)
        {
            Ar[arrayIndex] = countIndex;
            count[countIndex] -= 1;
            arrayIndex++;
        }
        else
        {
            countIndex++;
        }
        
    }
}


int main()
{
    int Array[] = {3, 1, 9, 7, 3, 1, 5, 6, 2};
    int size = sizeof(Array) / sizeof(int);

    printf("Before sort \n");
    Print(Array, size);

    printf("After sort \n");
    countSort(Array, size);
    Print(Array, size);

    return 0;
}
