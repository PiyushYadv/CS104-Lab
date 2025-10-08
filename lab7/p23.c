#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
  int data;
  struct StackNode *next;
};

struct StackNode *createNode(int data)
{
  struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void push(struct StackNode **top, int data)
{
  struct StackNode *newNode = createNode(data);
  newNode->next = *top;
  *top = newNode;
}

int pop(struct StackNode **top)
{
  if (*top == NULL)
  {
    printf("Stack underflow\n");
    return -1;
  }
  struct StackNode *temp = *top;
  int data = temp->data;
  *top = temp->next;
  free(temp);
  return data;
}

struct Queue
{
  struct StackNode *stack1;
  struct StackNode *stack2;
};

struct Queue *createQueue()
{
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->stack1 = NULL;
  queue->stack2 = NULL;
  return queue;
}

void enqueue(struct Queue *queue, int data)
{
  while (queue->stack1 != NULL)
  {
    push(&queue->stack2, pop(&queue->stack1));
  }

  push(&queue->stack1, data);

  while (queue->stack2 != NULL)
  {
    push(&queue->stack1, pop(&queue->stack2));
  }
}

int dequeue(struct Queue *queue)
{
  if (queue->stack1 == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }

  return pop(&queue->stack1);
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");

  struct Queue *queue = createQueue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);

  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Dequeued element: %d\n", dequeue(queue));

  dequeue(queue);

  return 0;
}
