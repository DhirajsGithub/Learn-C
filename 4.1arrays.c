#include <stdio.h>
#include <stdbool.h>

int main()
{
    // arrays
    int scores[3];
    scores[0] = 69;
    scores[1] = 420;
    scores[2] = 666;
    printf("scores[0] is %d\n", scores[0]);

    // arrays and loops
    int ages[] = {45, 67, 89, 21, 34, 56, 78, 90};
    int length = sizeof(ages) / sizeof(int); // it will calcualte the size of the array in bytes and divide it by the size of the data type
    for (int i = 0; i < length; i++)
    {
        printf("ages at %d is %d\n", i, ages[i]);
    }

    // multi-dimensional arrays
    // need to specify the number of columns in the array when declaring it
    int matrix[][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(int);
    // nested loops
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}