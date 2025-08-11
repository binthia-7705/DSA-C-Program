/*This program is to convert an infix expression to postfix expression*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum size of the stack
#define MAX 100
char stack[MAX];
int top = -1;

// Function to determine the precedence of operators
int precedence(char p)
{
    if (p == '+' || p == '-')
        return 1;
    else if (p == '*' || p == '/')
        return 2;
    else if (p == '^')
        return 3;
    else
        return 0; 
}

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

// Function to get the top element of the stack
char peek()
{
    if (!isempty())
        return stack[top];
    else
        return '\0'; 
}

//Function to push an element onto the stack
void push(char c)
{
    if (!isfull())
    {
        stack[++top] = c;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

//Function to pop an element from the stack
char pop()
{
    if (!isempty())
        return stack[top--];
    else
        return '\0'; 
}

//Function to convert infix expression to postfix expression
void infixToPostfix(char *a, char *output)
{
    int i = 0, j = 0;
    char t;
    while ((t = a[i]) != '\0')
    {
        // If the character is an operand, add it to the output
        if (isalnum(t))
        {
            output[j++] = t; 
        }
        // If the character is '(', push it onto the stack
        else if (t == '(')
        {
            push(t);
        }
        // If the character is ')', pop from the stack and append to output until an '(' is encountered
        else if (t == ')')
        {
            while (!isempty() && peek() != '(')
            {
                output[j++] = pop();
            }
            if (!isempty() && peek() == '(')
            {
                pop(); 
            }
        }
        // If the character is an operator, push it onto the stack
        else if (t == '+' || t == '-' || t == '*' || t == '/' || t == '^')
        {
            // Pop elements from the stack to the output if they have higher or equal precedence and append them to output
            while (!isempty() && precedence(peek()) >= precedence(t))
            {
                output[j++] = pop();
            }
            push(t);
        }
        i++;
    }
    // Pop all the remaining operators from the stack and append them to the output
    while (!isempty())
    {
        output[j++] = pop();
    }
    output[j] = '\0'; 
}

void main()
{
    //Inputting the infix expression
    char expression[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", expression);

    // Converting infix to postfix
    infixToPostfix(expression, postfix);

    // Displaying the infix and postfix expressions
    printf("Infix expression: %s\n", expression);
    printf("Postfix expression: %s\n", postfix);
}