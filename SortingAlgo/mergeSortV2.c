#include <stdio.h>
#include <stdlib.h>
// is stable
// space complexity is less
// is adaptive

void Print(int *Ar, int size)
{

    for (int k = 0; k < size; k++)
    {
        printf("%d ", Ar[k]);
    }
    printf("\n");
}

void merge(int Ar[], int low, int high, int mid, int size)
{

    int *output;
    output = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        output[i] = 0;
    }

    int lstr = low;
    int rstr = mid + 1;
    int outindx = low;

    while ((lstr <= mid) && (rstr <= high))
    {
        if (Ar[lstr] < Ar[rstr])
        {
            // printf("replacing %d with %d in position %d \n", Ar[n], leftArr[l], n);
            // Print(Ar, size);
            output[outindx] = Ar[lstr];
            lstr++;
            outindx++;
        }

        else
        {
            // printf("replacing %d with %d in position %d \n", Ar[n], rightArr[m], n);
            // Print(Ar, size);
            output[outindx] = Ar[rstr];
            rstr++;
            outindx++;
        }
    }

    while (lstr <= mid)
    {
        output[outindx] = Ar[lstr];
        lstr++;
        outindx++;
    }

    while (rstr <= high)
    {
        output[outindx] = Ar[rstr];
        rstr++;
        outindx++;
    }

    for (int i = low; i <= high; i++)
    {
        Ar[i]=output[i];
    }
    // Print(output, size);
}

void MergeSort(int Ar[], int size, int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;

        MergeSort(Ar, size, low, mid);
        MergeSort(Ar, size, mid + 1, high);
        merge(Ar, low, high, mid, size);
    }
}

int main()
{

    int Ar[] = {10, 7, 23, 13, 22, 53};
    int size = sizeof(Ar) / sizeof(int);

    printf("Before sort \n");

    Print(Ar, size);

    printf("\nAfter sort \n");

    MergeSort(Ar, size, 0, 5);

    Print(Ar, size);
}
