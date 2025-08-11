/*This program is for adding two square matrices and displaying the result*/

#include<stdio.h>

//This function is used to read and store elements in a matrix
void read(int a[100][100], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

//This function is used to add two matrices and store their result in a 3rd matrix
void addition(int a[100][100], int b[100][100], int sum[100][100], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

//This function is used to display the sum of the two matrices
void display(int a[100][100], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    //Read the elements of the two matrices
    int a[100][100], b[100][100];
    int n, m;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);
    read(a, n, m);
    read(b, n, m);

    //Add the matrices a and b and store the result in c
    int c[100][100];
    addition(a, b, c, n, m);

    //Display the result
    printf("The sum of the two matrices is:\n");
    display(c, n, m);
}