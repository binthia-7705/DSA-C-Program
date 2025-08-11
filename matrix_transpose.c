/*This program is for finding the transpose of a matrix given by the user*/

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

//This function is used to find the transpose of a matrix
void transpose(int a[100][100], int t[100][100], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            t[j][i] = a[i][j];
        }
    }
}

//This function is used to display a matrix
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
    //Create a matrix
    int a[100][100];
    printf("Enter the number of rows and columns: ");
    int n, m;
    scanf("%d %d", &n, &m);
    read(a, n, m);

    //Find the transpose of the matrix a
    int t[100][100];
    transpose(a, t, n, m);

    //Display the transpose matrix
    printf("The transposed matrix is:\n");
    display(t, m, n); 
}