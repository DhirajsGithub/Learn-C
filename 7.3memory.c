#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // for malloc and free functions // which are used to allocate and deallocate memory dynamically

void fun()
{
    // x ++; // this will give error because x is not declared
}

void fun2()
{
    // static memory allocation -> memory is allocated at compile time and it is allocated on stack
    // when we create a static variable it is allocated in memory and it is not deallocated until the program ends
    // it is not deallocated when the function ends like automatic variables
    int static a = 0;
    a++;
    printf("a is %d\n", a);
}

typedef struct
{
    char name[30];
    int age;
    bool isVarified;
} user;

// create a user struct and return a pointer to a user
user *createUser(char name[], int age, bool isVarified)
{
    user *newUser = malloc(sizeof(user)); // this will allocate memory for a user struct
    strcpy(newUser->name, name);          // newUser.name = name; // this will give error because newUser is a pointer
    newUser->age = age;
    newUser->isVarified = isVarified;
    return newUser;
}

int main()
{
    int x = 5; // scope of x is from here to the end of the main function, it won't be accessible outside of the main function
    if (true)
    {
        int y = 6; // scope of y is from here to the end of the if block, it won't be accessible outside of the if block
    }
    // y++; // this will give error because y is not in scope here it is in scope of if block
    fun2();
    fun2();
    fun2();
    fun2();
    fun2();

    // dynamic memory allocation -> memory is allocated at run time and it is allocated on heap
    // when we create a dynamic variable it is allocated in memory and it is deallocated when we want
    // it is not deallocated when the function ends like automatic variables
    // dynamic memory allocation is done using malloc and free functions
    // malloc function takes the size of the memory to be allocated in bytes and returns the address of the first byte of the allocated memory
    // malloc function returns void pointer (void *) which can be typecasted to any type of pointer
    // malloc function returns NULL if the memory cannot be allocated
    // free function takes the address of the first byte of the allocated memory and deallocates the memory
    // free function does not return anything
    // free function does not check if the memory is allocated or not so it is our responsibility to check if the memory is allocated or not before deallocating it
    // free function does not delete the pointer it just deallocates the memory so it is our responsibility to delete the pointer after deallocating the memory

    // int *ptr = (int *)malloc(5 * sizeof(int)); // allocating memory for 5 integers
    int size;
    printf("how many int elements do you want to store in the array?\n");
    scanf("%d", &size);
    int *arr = malloc(size * sizeof(int)); // allocating memory for size integers
    if (arr == NULL)
    {
        printf("memory cannot be allocated\n");
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        printf("enter the value of element %d ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("value of element %d is %d\n", i + 1, arr[i]);
    }

    // free function does not delete the pointer it just deallocates the memory so it is our responsibility to delete the pointer after deallocating the memory
    free(arr);

    // create a user struct and return a pointer to a user
    user *user1 = createUser("John Doe", 45, true);
    printf("user1 name is %s\n", user1->name);
    printf("user1 age is %d\n", user1->age);
    printf("user1 isVarified is %d\n", user1->isVarified);
    free(user1); // deallocating the memory allocated for user1

    return 0;
}