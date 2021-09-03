// best case O(nlog(n))
// average case O(nlog(n))
// worst case O(n2)
// is not stable
// in an inplace algo

#include <stdio.h>

void Print(int *Ar, int size)
{

    for (int k = 0; k < size; k++)
    {
        printf("%d ", Ar[k]);
    }
}

int Partition(int low, int high, int *Ar)
{
    int i = low + 1;
    int j = high;
    int pivot = Ar[low];
    int temp;

    do
    {
        while (Ar[i] <= pivot)
        {
            i++;
        }

        while (Ar[j] >= pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = Ar[i];
            Ar[i] = Ar[j];
            Ar[j] = temp;
        }
    } while (i < j);

    temp = Ar[low];
    Ar[low] = Ar[j];
    Ar[j] = temp;

    return j;
}

void QuickSort(int *Ar, int low, int high)
{

    int partitionIndex;

    if (low < high)
    {

        partitionIndex = Partition(low, high, Ar);
        QuickSort(Ar, low, partitionIndex - 1);
        QuickSort(Ar, partitionIndex + 1, high);
    }
}

int main()
{

    int Ar[] = {10, 7, 23, 13, 22, 53};
    int size = sizeof(Ar) / sizeof(int);

    printf("Before sort \n");

    Print(Ar, size);

    printf("\nAfter sort \n");

    QuickSort(Ar, 0, size - 1);

    Print(Ar, size);
}