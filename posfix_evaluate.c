/*This program is for evaluating a posfix expression*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define the maximum size of the stack
#define MAX 100
int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isempty()
{
    return (top == -1);
}

// Function to check if the stack is full
int isfull()
{
    return (top == MAX - 1);
}

// Function to push an element onto the stack
void push(int value)
{
    if (!isfull())
    {
        stack[++top] = value;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop()
{
    if (!isempty())
        return stack[top--];
    else
        return -1; // Error value
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *exp)
{
    int i;
    for (i = 0; exp[i]; i++)
    {
        // If the character is a digit, push it onto the stack
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            // Pop two operands from the stack
            int val2 = pop();
            int val1 = pop();
            switch (exp[i])
            {
            case '+':
                // Perform addition
                push(val1 + val2);
                break;
            case '-':
                // Perform subtraction
                push(val1 - val2);
                break;
            case '*':
                // Perform multiplication
                push(val1 * val2);
                break;
            case '/':
                // Perform division
                push(val1 / val2);
                break;
            case '^':
                // Perform exponentiation
                push(pow(val1, val2));
                break;
            }
        }
    }
    // Return the final result
    return pop();
}

void main()
{
    // Inputting the postfix expression
    char expression[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    // Evaluating the postfix expression
    int result = evaluatePostfix(expression);

    // Displaying the result
    printf("\nPostfix expression: %s\n", expression);
    printf("Result: %d\n", result);
}