#include <stdio.h>
#include <stdlib.h>

struct QueueNode
{
  int data;
  struct QueueNode *next;
};

struct Queue
{
  struct QueueNode *front, *rear;
};

struct QueueNode *createNode(int data)
{
  struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

struct Queue *createQueue()
{
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = queue->rear = NULL;
  return queue;
}

void enqueue(struct Queue *queue, int data)
{
  struct QueueNode *newNode = createNode(data);
  if (queue->rear == NULL)
  {
    queue->front = queue->rear = newNode;
    return;
  }
  queue->rear->next = newNode;
  queue->rear = newNode;
}

int dequeue(struct Queue *queue)
{
  if (queue->front == NULL)
    return -1;
  int data = queue->front->data;
  struct QueueNode *temp = queue->front;
  queue->front = queue->front->next;
  if (queue->front == NULL)
    queue->rear = NULL;
  free(temp);
  return data;
}

struct Stack
{
  struct Queue *q1;
  struct Queue *q2;
};

struct Stack *createStack()
{
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->q1 = createQueue();
  stack->q2 = createQueue();
  return stack;
}

int isEmpty(struct Queue *queue)
{
  return (queue->front == NULL);
}

void push(struct Stack *stack, int data)
{
  enqueue(stack->q2, data);

  while (!isEmpty(stack->q1))
  {
    enqueue(stack->q2, dequeue(stack->q1));
  }

  struct Queue *temp = stack->q1;
  stack->q1 = stack->q2;
  stack->q2 = temp;
}

int pop(struct Stack *stack)
{
  if (isEmpty(stack->q1))
    return -1;
  return dequeue(stack->q1);
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");

  struct Stack *stack = createStack();

  push(stack, 1);
  push(stack, 2);
  push(stack, 3);

  printf("Popped element: %d\n", pop(stack));
  printf("Popped element: %d\n", pop(stack));
  printf("Popped element: %d\n", pop(stack));

  return 0;
}
