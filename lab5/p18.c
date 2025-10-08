#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

struct Stack
{
  int top;
  int array[MAX_SIZE];
};

struct Stack *createStack()
{
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->top = -1;
  return stack;
}

void push(struct Stack *stack, int data)
{
  if (stack->top == MAX_SIZE - 1)
  {
    printf("Stack Overflow\n");
    return;
  }
  stack->array[++stack->top] = data;
}

int pop(struct Stack *stack)
{
  if (stack->top == -1)
  {
    printf("Stack Underflow\n");
    return INT_MIN;
  }
  return stack->array[stack->top--];
}

int getMin(struct Stack *dataStack)
{
  if (dataStack->top == -1)
  {
    printf("Stack is empty.\n");
    return INT_MIN;
  }
  int min = INT_MAX;
  for (int i = 0; i <= dataStack->top; i++)
  {
    if (dataStack->array[i] < min)
    {
      min = dataStack->array[i];
    }
  }
  return min;
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  struct Stack *dataStack = createStack();

  push(dataStack, 10);
  push(dataStack, 20);
  push(dataStack, 5);
  push(dataStack, 15);

  printf("Minimum element in the stack: %d\n", getMin(dataStack));

  pop(dataStack);
  pop(dataStack);

  printf("Minimum element in the stack after popping: %d\n", getMin(dataStack));

  free(dataStack);

  return 0;
}
