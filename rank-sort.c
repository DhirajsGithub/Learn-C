#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void rank_sort(int arr[], int size)
{

    int rank[size];
    // initializing rank 1 to all the elements
    for (int i = 0; i < size; i++)
    {
        rank[i] = 1;
    }
    for (int j = 1; j < size; j++)
    {
        for (int k = 0; k < j; k++)
        {
            if (arr[k] <= arr[j])
            {
                rank[j] += 1;
            }
            else
            {
                rank[k] += 1;
            }
        }
    }
    int temp[size];
    for (int i = 0; i < size; i++)
    {
        temp[rank[i] - 1] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int c = 3;
    int *p = &c;
    printf("%d\n", p);
    int arr[] = {3, 2, 8, 5, 1};
    rank_sort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}