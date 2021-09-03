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

int Max(int Ar[], int size)
{
    int maxElement = 0;

    for (int i = 0; i < size; i++)
    {
        if (maxElement < Ar[i])
        {
            maxElement = Ar[i];
        }
    }

    return maxElement;
}

void radixSort(int Arr[], int size)
{

    int max = Max(Arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(Arr, size, exp);
    }
}

void countSort(int Arr[], int size, int exp)
{
    int *count, *output;

    count = (int *)malloc(sizeof(int) * 10);
    output = (int *)malloc(sizeof(int) * size);

    // initializing each element of count = 0
    int oIndx = 0;
    int cIndx = 0;
    for (cIndx = 0; cIndx < 10; cIndx++)
    {
        count[cIndx] = 0;
        output[oIndx] = 0;
        oIndx++;
    }

    int arrIndx;
    for (arrIndx = 0; arrIndx < size; arrIndx++)
    {
        count[(Arr[arrIndx] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

    Print(count, 10);
    arrIndx = 0;
    cIndx = 0;
    // while (cIndx < 10)
    // {

    //     if (count[cIndx] > 0)
    //     {
    //         output[count[(Arr[arrIndx] / exp) % 10]] = Arr[arrIndx];
    //         arrIndx++;
    //         count[cIndx]--;
    //         cIndx++;
    //     }
    //     else
    //     {
    //         cIndx++;
    //     }
    // }

    // Print(output, size);
}

int main()
{

    int Ar[] = {10, 7, 23, 13, 7, 111, 33, 7};
    int size = sizeof(Ar) / sizeof(int);

    printf("Before sort \n");

    Print(Ar, size);

    printf("\nAfter sort \n");

    radixSort(Ar, size);

    Print(Ar, size);
}