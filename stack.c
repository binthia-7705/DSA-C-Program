/*This program is to perform the operations of a stack- push, pop, peek, and display*/
#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

//Check if stack is empty
int isEmpty()
{
    return top == -1;
}

//Check if stack is full
int isFull()
{
    return top == MAX - 1;
}

//Push a new element in stack
void push()
{
    int n;
    printf("Enter the value to push: ");
    scanf("%d", &n);
    if (isFull())
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = n;
    }

}

//Remove the top most element from stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

//Peek at the top most element without removing it
void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", stack[top]);
}

//Display all elements in the stack
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

//Main program to execute stack operations
void main()
{
    int choice;
    while (1)
    {
        //Choices for the user to choose
        printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            // Push operation
            push();
        }
        else if (choice == 2)
        {
            // Pop operation
            printf("The popped element: %d\n", pop());
        }
        else if (choice == 3)
        {
            // Peek operation
            peek();
        }
        else if (choice == 4)
        {
            // Display operation
            display();
        }
        else if (choice == 5)
        {
            // Exit
            break;
        }
        else
        {
            printf("Invalid choice: Please try again.\n");
        }
    }
    printf("Exiting the stack program.\n");
}