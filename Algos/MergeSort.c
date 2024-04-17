#include <stdio.h>
#include <string.h>

void merge(int arr[], int s, int mid, int e)
{
    int temp[e - s];
    int tempSize = e - s;
    int i = s;
    int j = mid;
    int k = 0;
    while (i < mid && j < e)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i < mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j < mid)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < tempSize; i++)
    {
        printf("%d ", temp[i]);
    }
    for (int l = 0; l < tempSize; l++)
    {
        arr[s + l] = temp[l];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (e - s == 1)
    {
        return;
    }
    int mid = (e + s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid, e);
    merge(arr, s, mid, e);
}

int main()
{
    int arr[] = {5, 6, 4, 7, 2};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}