#include <stdio.h>

// creating basic struct
// struct rectangle
// {
//     int length;
//     int width;
// };

// without using struct keyword
typedef struct
{
    int length;
    int width;
} rectangle;

typedef struct
{
    int x;
    int y;
} position;

// complex struct
typedef struct
{
    char owner[30];
    rectangle rect;
    position posi;
} buildingPlan;

int main()
{
    // declaring struct values
    // struct rectangle myRectangle = {2, 45};
    rectangle myRectangle = {2, 45};
    printf("width : %d. length : %d \n", myRectangle.width, myRectangle.length);

    buildingPlan myHouse = {"John Doe", {10, 20}, {5, 10}};
    printf("owner %s house width: %d length : %d | house position x : %d, y : %d \n", myHouse.owner, myHouse.rect.length, myHouse.rect.width, myHouse.posi.x, myHouse.posi.y);

    // array of structs
    position path[] = {{3, 5}, {7, 8}, {1, 2}, {9, 9}};
    for (int i = 0; i < 4; i++)
    {
        printf("x: %d, y: %d \n", path[i].x, path[i].y);
    }

    // pointers and struct
    buildingPlan *structPointer = &myHouse;
    printf("house location x:%d, y: %d \n", structPointer->posi.x, structPointer->posi.y);

    structPointer->rect.length = 999;
    structPointer->rect.width = 800;
    printf("house rect length:%d, width: %d \n", structPointer->rect.length, myHouse.rect.width);

    return 0;
}