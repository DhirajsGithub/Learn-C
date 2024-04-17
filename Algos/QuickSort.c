#include <stdio.h>
#include <string.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quickSort(int arr[], int i, int j)
{
    if (i >= j)
    {
        return;
    }

    int s = i;
    int e = j;
    int mid = (i + j) / 2;
    int pivot = arr[mid];

    while (s <= e)
    {
        while (arr[s] < pivot)
        {
            s++;
        }
        while (arr[e] > pivot)
        {
            e--;
        }
        if (s <= e)
        {
            swap(arr, s, e);
            s++;
            e--;
        }
    }

    quickSort(arr, i, e);
    quickSort(arr, s, j);
}

int main()
{
    int arr[] = {3, 4, 1, 8, 0, -3};
    int size = sizeof(arr) / sizeof(int);
    return 0;
}