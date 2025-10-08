#include <stdio.h>
#include <stdlib.h>

#define SIZE 400

typedef struct Queue
{
  int arr[SIZE];
  int front, rear;
} Queue;

Queue *createQueue()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = -1;
  queue->rear = -1;
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

void enqueue(Queue *q, int data)
{
  if (isFull(q))
  {
    printf("Queue is full\n");
    return;
  }
  if (isEmpty(q))
  {
    q->front = 0;
  }
  q->rear++;
  q->arr[q->rear] = data;
}

int dequeue(Queue *q)
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

int main()
{
  Queue *q = createQueue();
  // Breadth First Search
  int node;
  int i = 0;
  int visited[7] = {0, 0, 0, 0, 0, 0, 0};
  int a[7][7] = {
      {0, 1, 1, 1, 0, 0, 0},
      {1, 0, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0},
      {1, 0, 1, 0, 1, 0, 0},
      {0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 0},
  };
  printf("%d", i);
  enqueue(q, i);
  while (!isEmpty(q))
  {
    node = dequeue(q);
    for (int j = 0; j < 7; j++)
    {
      if (a[node][j] == 1 && visited[j] == 0)
      {
        printf("%d", j);
        visited[j] = 1;
        enqueue(q, j);
      }
    }
  }
  return 0;
}