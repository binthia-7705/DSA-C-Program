/*This program is to convert a sparse matrix as its representation with three columns: row, column, and value*/
#include <stdio.h>

//This function is used to input the elements of the sparse matrix
void input(int sparse_matrix[100][100], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter the elements of the sparse matrix [%d][%d]: ", i, j);
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
}

//This function is to calculate the no: of values in the sparse matrix
int value(int matrix[100][100], int row, int column)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

//This function is to convert the sparse matrix to its representation
void convert(int sparse_matrix[100][100], int represent[100][3], int row, int column)
{
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                represent[k][0] = i;
                represent[k][1] = j;
                represent[k][2] = sparse_matrix[i][j];
                k++;
            }
        }
    }
}

//This function is to print the sparse matrix representation
void print(int represent[100][3], int count)
{
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%d\t%d\n", represent[i][0]+1, represent[i][1]+1, represent[i][2]);
    }
}

//Main function to execute the program
void main()
{
    // Input the sparse matrix
    int sparse_matrix[100][100];
    int row, column;
    printf("Enter the no: of rows and columns of sparse matrix: ");
    scanf("%d %d", &row, &column);
    input(sparse_matrix, row, column);

    // Count the number of non-zero values and initialize the represent
    int count_value = value(sparse_matrix, row, column);
    int represent[100][3];

    // Convert the sparse matrix to its representation
    convert(sparse_matrix, represent, row, column);

    //Display the sparse matrix representation
    print(represent, count_value);
}