//The code below is to input two polynomial equations and find the sum of the two equations.
#include <stdio.h>
#include <stdlib.h>

// This function is used to input the coefficients of a polynomial equation
void input(int *array, int n)
{
    int i;
    for(i = 0; i <= n; i++)
    {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &array[i]);
    }
    printf("\n");
}

// This function is used to add two polynomial equations
void sum(int *array1, int *array2, int *sum_array, int n1, int n2)
{
    int i=0,j=0,k=0;
    while (i <= n1 && j <= n2)
    {
        sum_array[k++] = array1[i++] + array2[j++];
    }
    while (i <= n1)
    {
        sum_array[k++] = array1[i++];
    }
    while (j <= n2)
    {
        sum_array[k++] = array2[j++];
    }
}

// This function is used to print the sum of two polynomial equations
void print(int *array, int n)
{
    printf("The sum of the two polynomial equations is:\n");
    for (int i = n; i >= 0; i--)
    {
        if (i == 0)
            printf(" + %d", array[i]);
        else if (i == n)
        {
            printf("%dx^%d ", array[i], i);
        }
        
        else
            printf("+ %dx^%d", array[i], i);
    }
    printf("\n");
}


// Main function to execute the program
void main()
{
    // Input the highest degree of the polynomial equations
    int degree1, degree2;
    int degree;

    // Input coefficients and degree for 1st polynomial equations
    printf("Enter the degree of the 1st polynomial equation: ");
    scanf("%d", &degree1);
    int *array1 = (int *)malloc((degree1 + 1) * sizeof(int));
    printf("Input coefficients for the 1st polynomial equation:\n");
    input(array1, degree1);

    // Input coefficients and degree for 2nd polynomial equations
    printf("Enter the degree of the 2nd polynomial equation: ");
    scanf("%d", &degree2);
    int *array2 = (int *)malloc((degree2 + 1) * sizeof(int));
    printf("Input coefficients for the 2nd polynomial equation:\n");
    input(array2, degree2);

    // Calculate the sum of the two polynomial equations
    if (degree1>degree2)
        degree = degree1;
    else
        degree = degree2;
    int *sum_array = (int *)malloc((degree + 1) * sizeof(int));
    sum(array1, array2, sum_array, degree1, degree2);

    // Print the sum of the two polynomial equations
    print(sum_array, degree);
}
