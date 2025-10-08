#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Stack
{
  struct Node *top;
};

void push(struct Stack *stack, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

int pop(struct Stack *stack)
{
  if (stack->top == NULL)
  {
    printf("Stack is empty. Cannot pop.\n");
    return -1;
  }
  int data = stack->top->data;
  struct Node *temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return data;
}

int peek(struct Stack *stack)
{
  if (stack->top == NULL)
  {
    printf("Stack is empty. Cannot peek.\n");
    return -1;
  }
  return stack->top->data;
}

int isEmpty(struct Stack *stack)
{
  return stack->top == NULL;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->top = NULL;

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);

  printf("Top element: %d\n", peek(stack));

  printf("Popping elements: ");
  while (!isEmpty(stack))
  {
    printf("%d ", pop(stack));
  }
  printf("\n");

  pop(stack); // Trying to pop from an empty stack

  free(stack);

  return 0;
}
