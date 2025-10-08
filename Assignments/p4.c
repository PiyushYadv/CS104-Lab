#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the stack
typedef struct
{
  int data[MAX_SIZE];
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
void push(Stack *stack, int value)
{
  if (isFull(stack))
  {
    printf("Stack is full. Push operation failed.\n");
    return;
  }

  stack->data[++stack->top] = value;
  printf("Pushed element: %d\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack is empty. Pop operation failed.\n");
    return -1;
  }

  int value = stack->data[stack->top--];
  printf("Popped element: %d\n", value);
  return value;
}

int main()
{
  printf("Piyush Yadav\n 23/CS/301\n");
  Stack stack;
  int choice, value;

  initializeStack(&stack);

  do
  {
    printf("\nStack Operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to push: ");
      scanf("%d", &value);
      push(&stack, value);
      break;
    case 2:
      value = pop(&stack);
      if (value != -1)
        printf("Popped element: %d\n", value);
      break;
    case 3:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice. Please enter a valid option.\n");
    }
  } while (choice != 3);

  return 0;
}
