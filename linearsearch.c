/* This file contains the code for performing linear search on an array */
#include<stdio.h>

//This function is used to read elements into the array
void read(int array[], int n)
{
  for(int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

// This function is used to find an element in the array using linear search.
int linear_search(int array[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(array[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    //Create an array
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[100];
    read(array, n);

    //Input key to search in the array using linear search
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result= linear_search(array, n, key);
    if(result == -1)
    {
        printf("Element not found in the array.\n");
    }
    else
    {
        printf("Element %d found at position %d\n", key, result);
    }
}