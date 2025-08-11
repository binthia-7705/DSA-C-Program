/*This file contains the code for the binary search of an array input by user.
  There are functions to perform - reading, sorting, searching and displaying of the array elements*/

#include <stdio.h>

//The function is used to input elements in the array
void read (int array[], int n)
{
    int i=0;
    while (i < n)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
        i++;
    }
}

//This function is used to sort the array in ascending order using bubble sort
void sort(int array[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//This function is used to find the position of an element in the array using binary search
int search(int array[], int n, int key)
{
    
    int l=0, u=n, mid;
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (array[mid] == key)
        {
            return mid; 
        }
        else if (array[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            u = mid - 1;
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
    int a[100];
    read(a, n);

    //Sort the array
    sort(a, n);

    //Input a key to search in the array using binary search
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = search(a, n, key);
    if (result != -1)
    {
        printf("Element %d found at position %d\n", key, result + 1);
    }
    else
    {
        printf("Element %d not found\n", key);
    }
  }