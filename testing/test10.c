#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Queue
{
  int arr[SIZE];
  int front;
  int rear;
} Queue;

Queue *createDeque()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = -1, queue->rear = -1;
  return queue;
}

int isFull(Queue *q)
{
  return (q->rear == SIZE - 1);
}

int isEmpty(Queue *q)
{
  return (q->front == -1 && q->rear == -1);
}

void enQueueFront(Queue *q, int data)
{
  if (isFull(q))
  {
    printf("Queue Full\n");
    return;
  }
  else
  {
    if (q->front == -1 && q->rear == -1)
    {
      q->front = 0;
      q->rear = 0;
    }
    else if (q->front == 0)
    {
      q->front = SIZE - 1;
    }
    else
    {
      q->front--;
    }
    q->arr[q->front] = data;
  }
}

void enQueueBack(Queue *q, int data)
{
  if (isFull(q))
  {
    printf("Queue Full\n");
    return;
  }
  else
  {
    if (q->front == -1)
    {
      q->front = 0;
      q->rear = 0;
    }
    else if (q->rear == SIZE - 1)
    {
      q->rear = 0;
    }
    else
    {
      q->rear++;
    }
    q->arr[q->rear] = data;
  }
}

int deQueueFront(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
    return -1;
  }
  int value = q->arr[q->front];
  q->front++;
  if (q->front > q->rear)
  {
    q->front = q->rear = -1;
  }
  return value;
}

int deQueueBack(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
    return -1;
  }
  int value = q->arr[q->rear];
  q->rear--;
  if (q->front > q->rear)
  {
    q->front = q->rear = -1;
  }
  return value;
}

void printQueue(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty");
    return;
  }
  printf("Queue contains: ");
  for (int i = q->front; i < q->rear + 1; i++)
  {
    printf("%d ", q->arr[i]);
  }
  printf("\n");
}

int main()
{
  Queue *q = createDeque();
  enQueueBack(q, 3);
  enQueueBack(q, 2);
  enQueueBack(q, 1);
  deQueueFront(q);
  enQueueFront(q, 4);
  printQueue(q);
  return 0;
}