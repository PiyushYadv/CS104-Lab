#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
  int data;
  int minSoFar; // Variable to store the minimum value up to this node
  struct Node *next;
};

struct Stack
{
  struct Node *top;
};

struct Stack *createStack()
{
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->top = NULL;
  return stack;
}

void push(struct Stack *stack, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  if (stack->top == NULL)
  {
    newNode->minSoFar = data;
  }
  else
  {
    newNode->minSoFar = data < stack->top->minSoFar ? data : stack->top->minSoFar;
  }
  newNode->next = stack->top;
  stack->top = newNode;
}

int pop(struct Stack *stack)
{
  if (stack->top == NULL)
  {
    printf("Stack is empty. Cannot pop.\n");
    return INT_MIN;
  }
  struct Node *temp = stack->top;
  int poppedData = temp->data;
  stack->top = stack->top->next;
  free(temp);
  return poppedData;
}

int getMin(struct Stack *stack)
{
  if (stack->top == NULL)
  {
    printf("Stack is empty.\n");
    return INT_MIN;
  }
  return stack->top->minSoFar;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");

  struct Stack *stack = createStack();

  push(stack, 10);
  push(stack, 20);
  push(stack, 5);
  push(stack, 15);

  printf("Minimum element in the stack: %d\n", getMin(stack));

  pop(stack);
  pop(stack);

  printf("Minimum element in the stack after popping: %d\n", getMin(stack));

  free(stack);

  return 0;
}
