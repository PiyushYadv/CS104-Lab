#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent the stack
typedef struct
{
  char data[MAX_SIZE];
  int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *stack)
{
  stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
  return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
  return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(Stack *stack, char value)
{
  if (isFull(stack))
  {
    printf("Stack is full. Push operation failed.\n");
    return;
  }

  stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty. Pop operation failed.\n");
    return '\0';
  }

  return stack->data[stack->top--];
}

// Function to get the precedence of operators
int precedence(char op)
{
  if (op == '^')
    return 3;
  else if (op == '*' || op == '/' || op == '%')
    return 2;
  else if (op == '+' || op == '-')
    return 1;
  else
    return -1;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix)
{
  Stack stack;
  initializeStack(&stack);

  int i, j = 0;
  for (i = 0; infix[i] != '\0'; i++)
  {
    char c = infix[i];

    if (isalnum(c))
    { // If operand, add it to the postfix expression
      postfix[j++] = c;
    }
    else if (c == '(')
    { // If '(' push it to the stack
      push(&stack, c);
    }
    else if (c == ')')
    { // If ')' pop and output from the stack until '(' is encountered
      while (!isEmpty(&stack) && stack.data[stack.top] != '(')
      {
        postfix[j++] = pop(&stack);
      }
      pop(&stack); // Pop '(' from the stack (and discard)
    }
    else
    { // If operator
      while (!isEmpty(&stack) && precedence(c) <= precedence(stack.data[stack.top]))
      {
        postfix[j++] = pop(&stack); // Pop and output operators from the stack with higher or equal precedence
      }
      push(&stack, c); // Push the current operator to the stack
    }
  }

  // Pop and output remaining operators from the stack
  while (!isEmpty(&stack))
  {
    postfix[j++] = pop(&stack);
  }

  postfix[j] = '\0'; // Null terminate the postfix expression
}

int main()
{
  printf("Piyush Yadav\n 23/CS/301\n");
  char infix[MAX_SIZE], postfix[MAX_SIZE];

  printf("Enter an infix expression: ");
  fgets(infix, sizeof(infix), stdin);
  infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline if present

  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);

  return 0;
}
