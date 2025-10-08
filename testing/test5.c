#include <stdio.h>
#include <stdlib.h>

// #define SIZE 5

typedef struct node
{
  int data;
  struct node *next;
} Node;

// typedef struct Stack
// {
//   int arr[SIZE];
//   int top;
// } Stack;

typedef struct NodeStack
{
  Node *top;
} NodeStack;

// Stack *createStack()
// {
//   Stack *stack = (Stack *)malloc(sizeof(Stack));
//   stack->top = -1;
//   return stack;
// }

NodeStack *createNodeStack()
{
  NodeStack *nodeStack = (NodeStack *)malloc(sizeof(NodeStack));
  nodeStack->top = NULL;
  return nodeStack;
}

int isEmptyLL(NodeStack *s)
{
  return s->top == NULL;
}

// int isFullLL(NodeStack *s){} //Can never be full

// int isEmpty(Stack *s)
// {
//   if (s->top == -1)
//     return 1;
//   return 0;
// }

// int isFull(Stack *s)
// {
//   if (s->top == SIZE)
//     return 1;
//   return 0;
// }

void displayLL(NodeStack *s)
{
  if (isEmptyLL(s))
  {
    printf("Stack empty\n");
    return;
  }
  Node *temp = s->top;
  while (temp->next != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("%d\n", temp->data);
}

void peekLL(NodeStack *s)
{
  if (isEmptyLL(s))
  {
    printf("Stack empty\n");
    return;
  }
  printf("%d\n", s->top->data);
}

void pushLL(NodeStack *s, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = s->top;
  s->top = newNode;
}

void popLL(NodeStack *s)
{
  printf("%d\n", s->top->data);
  Node *temp = s->top;
  s->top = s->top->next;
  free(temp);
}

// void display(Stack *s)
// {
//   if (isEmpty(s))
//   {
//     printf("Stack empty\n");
//     return;
//   }
//   for (int i = 0; i <= s->top; i++)
//   {
//     printf("%d ", s->arr[i]);
//   }
//   printf("\n");
// }

// void peek(Stack *s)
// {
//   if (isEmpty(s))
//   {
//     printf("Stack empty\n");
//     return;
//   }
//   printf("%d", s->arr[s->top]);
// }

// void push(Stack *s, int data)
// {
//   if (isFull(s))
//   {
//     printf("Stack full\n");
//     return;
//   }
//   s->top++;
//   s->arr[s->top] = data;
// }

// void pop(Stack *s)
// {
//   printf("%d\n", s->arr[s->top--]);
// }

int main()
{
  // Stack *s1 = createStack();
  // peek(s1);
  // push(s1, 1);
  // push(s1, 2);
  // push(s1, 3);
  // push(s1, 4);
  // push(s1, 5);
  // pop(s1);
  // display(s1);
  NodeStack *s1 = createNodeStack();
  pushLL(s1, 1);
  pushLL(s1, 2);
  pushLL(s1, 3);
  displayLL(s1);
  peekLL(s1);
  popLL(s1);
  displayLL(s1);
  return 0;
}